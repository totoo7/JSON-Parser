#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
using namespace std;
class Command {
public:
    Command(const string &name, size_t paramCount);
    string getName() const;
    size_t getParamCount() const;
private:
    string name;
    size_t paramCount;
};

#endif