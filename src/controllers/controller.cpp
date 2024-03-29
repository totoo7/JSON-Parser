#include "controller.h"

void Controller::processUserInput(const string& userInput) {
    if (!Validator::isValidCommand(userInput)) {
        cerr << "Invalid command" << endl; 
        return;
    }
    if (userInput == "open") {
        //call for service
    } else if (userInput == "close ") {
        //call for service
    }
    //TODO etc
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
}