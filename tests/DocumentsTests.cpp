#include "../src/Documents/Documents.h"
#include <gtest/gtest.h>

TEST(DocumentsTest, PdfDocument) {
    DocumentsExample::PdfDocument pdf("test.pdf");
    auto text = pdf.getText();
    ASSERT_FALSE(text.empty());
    EXPECT_EQ(text[0], "Text from PDF");
}

TEST(DocumentsTest, HtmlDocument) {
    DocumentsExample::HtmlDocument html("test.html");
    auto text = html.getText();
    ASSERT_FALSE(text.empty());
    EXPECT_EQ(text[0], "Text from HTML");
}

TEST(DocumentsTest, FactoryCreation) {
    DocumentsExample::DocumentFactory factory;
    factory.add("pdf", [](auto path) { return std::make_unique<DocumentsExample::PdfDocument>(path); });
    
    auto doc = factory.open("test.pdf");
    ASSERT_NE(doc, nullptr);
    auto text = doc->getText();
    ASSERT_FALSE(text.empty());
    EXPECT_EQ(text[0], "Text from PDF");
}
