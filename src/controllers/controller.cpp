#include "controller.h"
#include "JsonFactory.h"
void Controller::processUserInput(const string& userInput) {
    vector<string> userCommands = Validator::splitCommand(userInput, ' ');
    string command = userCommands[0];
    if (!Validator::isValidCommand(command)) {
        cerr << "Invalid command" << endl; 
        return;
    }
    if (command == "open") {
        JsonFactory::get().parseFile(userCommands[1]);
    } else if (command == "save") {
        //TODO
    } else if (command == "saveas") {
        //TODO
    } else if (command == "exit") {
        //TODO
    }
    //TODO etc
}


    //?
    /*
    using CommandFunction = void (Controller::*)();
    struct CommandEntry {
        string command;
        CommandFunction function;
    };

    for (const auto& entry : commandList) {
        if (entry.command == userInput) {
            If found, call the corresponding function
            (this->*entry.function)();
            return;
        }
    }
    */
   //?