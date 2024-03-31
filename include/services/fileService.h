#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class fileService {
    private: 
        struct File {
            string fileName;
            string content;
        };
        File currentFile;
    public:
        bool open(const string& fileName);
        bool save();
        bool saveAs(const string& newFileName);
};