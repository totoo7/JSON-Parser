#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H

#include "Command.hpp"
#include <vector>

class CommandManager
{
public:
    CommandManager();
    bool isValidCommand(const string &name) const;
    const Command *getCommand(const string &name) const;
    void toLowerCase(string& name);
private:
    vector<Command> commands;
};

#endif