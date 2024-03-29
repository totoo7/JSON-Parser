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
        "saveas"
    };

bool Validator::isValidCommand(const string& command) {
    for (const auto& validCommand : validCommands) {
        if (command == validCommand) return true;
    }
    return false;
}

const vector<string> Validator::getValidCommands() {
    return validCommands;
}
