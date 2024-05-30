#ifndef INTERFACE_H
#define INTERFACE_H

#include "JsonFactory.hpp"
#include "Validator.hpp"
class Interface
{
public:
    Interface();
    void run();
    void update();
    void processUserInput(const string& userInput);
    bool openFile(const string& filename);
    void saveAs(const string &path, string &newFilename);
    void save() const;
    void printMenu() const;
    ~Interface();
private:
    bool isRunning;
    string filename;
    bool isLoadedFile;
    Json *current;
};

#endif