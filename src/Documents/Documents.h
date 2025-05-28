#ifndef DOCUMENTS_H
#define DOCUMENTS_H

#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <functional>

namespace DocumentsExample {

    struct IDocument {
        virtual ~IDocument() {}
        virtual std::vector<std::string> getText() = 0;
    };

    class PdfDocument : public IDocument {
    private:
        std::string m_path;
    public:
        PdfDocument(std::string path);
        std::vector<std::string> getText() override;
    };

    class HtmlDocument : public IDocument {
    private:
        std::string m_path;
    public:
        HtmlDocument(std::string path);
        std::vector<std::string> getText() override;
    };

    class OdtDocument : public IDocument {
    private:
        std::string m_path;
    public:
        OdtDocument(std::string path);
        std::vector<std::string> getText() override;
    };

    class DocumentFactory {
    private:
        std::unordered_map<std::string, std::function<std::unique_ptr<IDocument>(std::string)>> m_readers;
    public:
        void add(const std::string& extension, const std::function<std::unique_ptr<IDocument>(std::string)>& reader);
        std::unique_ptr<IDocument> open(std::string path);
    };

    void test_documents();
}

#endif // DOCUMENTS_H
