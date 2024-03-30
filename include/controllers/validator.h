#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Validator {
    public: 
        static bool isValidCommand(const string& command);
        static const vector<string> getValidCommands();
        static const vector<string> splitCommand(const string& command, char delimeter); 
    private: 
        static const vector<string> validCommands;
};