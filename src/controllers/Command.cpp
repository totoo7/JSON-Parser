#include "Command.hpp"

Command::Command(const string &name, size_t paramCount) : name(name), paramCount(paramCount) {}

string Command::getName() const 
{
    return name;
}

size_t Command::getParamCount() const 
{
    return paramCount;
}