#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Validator {
    public: 
        static bool isValidCommand(const string& command);
        static const vector<string> getValidCommands();
    private: 
        static const vector<string> validCommands;
};