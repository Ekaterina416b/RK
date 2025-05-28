#include "Documents.h"
#include <iostream>
#include <stdexcept>

namespace DocumentsExample {

    PdfDocument::PdfDocument(std::string path) : m_path{path} {}
    std::vector<std::string> PdfDocument::getText() { return {"Text from PDF"}; }

    HtmlDocument::HtmlDocument(std::string path) : m_path{path} {}
    std::vector<std::string> HtmlDocument::getText() { return {"Text from HTML"}; }

    OdtDocument::OdtDocument(std::string path) : m_path{path} {}
    std::vector<std::string> OdtDocument::getText() { return {"Text from ODT"}; }

    void DocumentFactory::add(const std::string& extension,
                            const std::function<std::unique_ptr<IDocument>(std::string)>& reader) {
        m_readers.emplace(extension, reader);
    }

    std::unique_ptr<IDocument> DocumentFactory::open(std::string path) {
        auto lastDot = path.find_last_of('.');
        if (lastDot != std::string::npos) {
            std::string extension{path.substr(lastDot + 1)};
            auto& reader = m_readers[extension];
            return reader(path);
        }
        throw std::invalid_argument{"Trying to open a file with no extension"};
    }

    void test_documents() {
        DocumentFactory factory;
        factory.add("pdf", [](auto path) { return std::make_unique<PdfDocument>(path); });
        factory.add("html", [](auto path) { return std::make_unique<HtmlDocument>(path); });
        factory.add("odt", [](auto path) { return std::make_unique<OdtDocument>(path); });

        auto document = factory.open("file.html");
        std::cout << document->getText().front();
    }
}
