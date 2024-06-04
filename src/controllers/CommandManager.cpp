#include "CommandManager.hpp"

CommandManager::CommandManager() 
{
    commands.push_back({"open", 1});
    commands.push_back({"save", 0});
    commands.push_back({"saveas", 2});
    commands.push_back({"parse", 0});
    commands.push_back({"exit", 0});
    commands.push_back({"search", 1});
    commands.push_back({"set", 2});
    commands.push_back({"erase", 1});
    commands.push_back({"move", 2});
    commands.push_back({"create", 2});  
}

bool CommandManager::isValidCommand(const string &name) const 
{
    for (const auto &command : commands) 
    {
        if (command.getName() == name)
        {
            return true;
        }
    }
    return false;
}

void CommandManager::toLowerCase(string &name) 
{
    for(size_t i = 0; i < name.size(); i++) 
    {
        if (name[i] >= 'A' && name[i] <=  'Z')
        {
            name += 32;
        }
    }
}

const Command* CommandManager::getCommand(const string &name) const
{
    for (const auto &command : commands) 
    {
        if (command.getName() == name) 
        {
            return &command;
        }
    }
    return nullptr;
}