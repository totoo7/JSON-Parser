#include "Validator.hpp"

const vector<string> Validator::validCommands =
    {
        "open",
        "close",
        "saveas",
        "exit",
        "parse",
        "save",
        "saveas",
        "search",
        "set",
        "erase",
        "move",
        "create"
    };

bool Validator::isValidCommand(const string &command)
{
    for (const auto &validCommand : validCommands)
    {
        if (command == validCommand)
            return true;
    }
    return false;
}

void Validator::toLowerCase(string& value) 
{
    for(int i = 0; i < value.size(); i++) 
    {
        if (value[i] >= 'A' && value[i] <=  'Z')
        {
            value[i] += 32;
        }
    }
}

const vector<string> Validator::getValidCommands()
{
    return validCommands;
}
