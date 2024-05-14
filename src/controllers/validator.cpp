#include "validator.h"

const vector<string> Validator::validCommands =
    {
        "open",
        "close",
        "saveas",
        "exit",
        "validate",
        "print",
        "search",
        "contains",
        "set",
        "create",
        "delete",
        "move",
        "save",
        "saveas"};

bool Validator::isValidCommand(const string &command)
{
    for (const auto &validCommand : validCommands)
    {
        if (command == validCommand)
            return true;
    }
    return false;
}

const vector<string> Validator::splitCommand(const string &command, char delimeter)
{
    vector<string> tokens;
    string token;
    int start = 0, end = 0;
    while ((end = command.find(delimeter, start)) != string::npos)
    {
        token = command.substr(start, end - start);
        tokens.push_back(token);
        start = end + 1;
    }
    token = command.substr(start);
    tokens.push_back(token);
    return tokens;
}

const vector<string> Validator::getValidCommands()
{
    return validCommands;
}
