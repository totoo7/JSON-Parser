#include "controller.hpp"

void Controller::processUserInput(const string &userInput)
{
    vector<string> userCommands = Validator::splitCommand(userInput, ' ');
    string command = userCommands[0];
    if (!Validator::isValidCommand(command))
    {
        cerr << "Invalid command" << endl;
        return;
    }
    if (command == "open")
    {
        Json* json = JsonFactory::get().parseFile(userCommands[1]);
        if (json) {
            json->print();
        }
        delete json;
    }
    else if (command == "save")
    {
        // TODO
    }
    else if (command == "saveas")
    {
        // TODO
    }
    else if (command == "exit")
    {
        // TODO
    }
    // TODO etc
}