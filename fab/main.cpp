#include <iostream>
#include <memory>
using namespace std;


class Document {
public:
    virtual void open() = 0;
    virtual void close() = 0;
    virtual ~Document() {}
};


class TextDocument : public Document {
public:
    void open() override  { cout << "Open text document\n"; }
    void close() override { cout << "Close text document\n"; }
};

class SpreadsheetDocument : public Document {
public:
    void open() override  { cout << "Open spreadsheet document\n"; }
    void close() override { cout << "Close spreadsheet document\n"; }
};


class Application {
public:
    virtual unique_ptr<Document> createDocument() = 0;
    virtual ~Application() {}
};


class TextApplication : public Application {
public:
    unique_ptr<Document> createDocument() override {
        return make_unique<TextDocument>();
    }
};

class SheetApplication : public Application {
public:
    unique_ptr<Document> createDocument() override {
        return make_unique<SpreadsheetDocument>();
    }
};


int main() {
    Application* app = new TextApplication();
    auto doc = app->createDocument();
    doc->open();
    doc->close();
    delete app;
}
