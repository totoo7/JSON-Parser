#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Validator
{
public:
    static bool isValidCommand(const string &command);
    static const vector<string> getValidCommands();
    static void toLowerCase(string &value);
private:
    static const vector<string> validCommands;
};

#endif