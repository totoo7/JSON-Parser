#include "Interface.hpp"
#include "Utilities.hpp"
Interface::Interface() : json(nullptr), isRunning(true), filename("Null"), isLoadedFile(false), manager() {}

bool Interface::openFile(const string &filename)
{
    Json *temp = nullptr;
    try
    {
        temp = JsonFactory::get().parseFile(filename);
    }
    catch (invalid_argument &e)
    {
        cout << e.what();
        cout << endl;
        return false;
    }

    if (json) delete json;
    json = temp;
    this->filename = filename;
    if (json) isLoadedFile = true;
    return isLoadedFile;
}

void Interface::save() const
{
    ofstream ofs;
    ofs.open(filename, ios::out | ios::trunc);
    if (!ofs.is_open())
        return;
    if (json)
        ofs << json->toString();
    ofs.close();
}

void Interface::saveAs(const string &path, string &newFilename)
{
    ofstream ofs;
    string content(path);

    if (newFilename.find(".json") == string::npos) 
    {
        newFilename += ".json";
    }
    content += newFilename;
    ofs.open(content, ios::out | ios::trunc);
    if (!ofs.is_open())
        return;
    if (json)
        ofs << json->toString();
    ofs.close();
}

void Interface::run()
{
    while (isRunning) 
        update();
}

void Interface::update()
{
    string input;
    printMenu();
    getline(cin, input);
    processUserInput(input);
}

void Interface::printMenu() const
{
    cout << endl;
    if (isLoadedFile)
        cout << "File "<< filename <<" is loaded." << endl;
    else 
        cout << "There is no loaded file." << endl;

    cout << ">Enter 'open' then 'filename' to open a new file." << endl;
    cout << ">Enter 'exit' to quit." << endl;
    if (isLoadedFile) 
    {
        cout << ">Enter 'parse' to parse and print the loaded file." << endl;
        cout << ">Enter 'save' to save the loaded file." << endl;
        cout << ">Enter 'saveas' then 'path' and 'filename' to save the loaded file to a new location." << endl;
        cout << ">Enter 'search' then 'key' to check if an object with this key exists. Result is printed in the terminal." << endl;
        cout << ">Enter 'contains' then 'value' to check if a key with this value exists. Result is printed in the terminal." << endl;
        cout << ">Enter 'set' then 'path' and 'value' to set new value of existing key." << endl;
        cout << ">Enter 'erase' then 'path' to erase the given key." << endl;
        cout << ">Enter 'move' then 'path from' then 'path to' to move key. Only elements that have key can be moved." << endl;
        cout << ">Enter 'create' then 'path' then 'new value' to create new value." << endl;
        cout << ">Enter 'help' for more info on how to use the commands. " << endl;
    }
}

void Interface::processUserInput(const string& userInput) {
    vector <string> userCommands = UTILITIES::tokenize(userInput);
    if (userCommands.empty()) return;

    manager.toLowerCase(userCommands[0]);
    string commandName = userCommands[0];
    
    if (!manager.isValidCommand(commandName)) {
        cerr << "Invalid command" << endl;
        return;
    }

    const Command* commandTemp = manager.getCommand(commandName);
    if (userCommands.size() - 1 < commandTemp->getParamCount() || userCommands.size() - 1 > commandTemp->getParamCount()) 
    {
        cerr << "Invalid number of parameters for command " << commandTemp->getName() << ". Expected: " << commandTemp->getParamCount() << "." <<  endl; 
        return;
    }
    string command = commandTemp->getName();
    if (command == "open")
    {
        openFile(userCommands[1]);
    }
    else if (command == "save")
    {
        save();
        cout << "Saving..." << endl;
    }
    else if (command == "saveas")
    {
        saveAs(userCommands[1], userCommands[2]);
        cout << "Saving..." << endl;
    } 
    else if (command == "parse") 
    {
        if (json) json->print();
    }
    else if (command == "exit")
    {
        isRunning = false;
        cout << "Exiting..." << endl;
    } 
    else if (command == "search") 
    {
        json->search(userCommands[1]);
    } 
    else if (command == "set") 
    {
        json->set(userCommands[1], userCommands[2]);
    }
    else if (command == "erase")
    {
        json->erase(userCommands[1]);
    }
    else if (command == "move") 
    {
        json->move(userCommands[1], userCommands[2]); 
    }
    else if (command == "create")
    {
        json->create(userCommands[1], userCommands[2]);
    }
    else if (command == "contains")
    {
        json->contains(userCommands[1]);
    }
    else if (command == "help") 
    {
        cout << "1) When giving a path use \"/\" as a delimeter to specify where the key is." << endl;
        cout << "Example: " << endl;
        cout << "set foo/bar \"value\", where bar is a key in foo." << endl;
        cout << "2) When trying to move an object in the root of the JSON file use \"./\"." << endl;
        cout << "Example: " << endl;
        cout << "move foo/bar ./, where bar is a key in foo and it will be moved to the top-level elements." << endl;
        cout << "3) When trying to create or move an element in array use array/" << endl;
        cout << "Example: " << endl;
        cout << "create foo/ \"bar\", where foo is an array and bar is an element that will be added." << endl;
    }
}

Interface::~Interface() {
    delete json;
}