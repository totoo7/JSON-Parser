#include "Interface.hpp"
#include "Utilities.hpp"
Interface::Interface() : current(nullptr), isRunning(true), filename("Null"), isLoadedFile(false) {}

bool Interface::openFile(const string &filename)
{
    if (current) delete current;
    try
    {
        current = JsonFactory::get().parseFile(filename);
    }
    catch (invalid_argument &e)
    {
        cout << e.what();
        return false;
    }
    this->filename = filename;
    if (current) isLoadedFile = true;
    return isLoadedFile;
}

void Interface::save() const
{
    ofstream ofs;
    ofs.open(filename, ios::out | ios::trunc);
    if (!ofs.is_open())
        return;
    if (current)
        ofs << current->toString();
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
    if (current)
        ofs << current->toString();
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
        cout << ">Enter 'set' then 'path' and 'value' to set new value of existing key." << endl;
        cout << ">Enter 'erase' then 'path' to erase the given key." << endl;
        cout << ">Enter 'move' then 'path from' then 'path to' to move key" << endl;
        cout << ">Enter 'create' then 'path' then 'new value' to create new value." << endl;
    }
}

void Interface::processUserInput(const string& userInput) {
    vector <string> userCommands = UTILITIES::tokenize(userInput);
    Validator::toLowerCase(userCommands[0]);
    string command = userCommands[0];
    if (!Validator::isValidCommand(command))
    {
        cerr << "Invalid command" << endl;
        return;
    }
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
        if (current) current->print();
    }
    else if (command == "exit")
    {
        isRunning = false;
        cout << "Exiting..." << endl;
    } 
    else if (command == "search") 
    {
        current->search(userCommands[1]);
    } 
    else if (command == "set") 
    {
        if (userCommands[1] == "" && userCommands[2] == "")
        {
            cerr << "Invalid path or value." << endl;
        } 
        current->set(userCommands[1], userCommands[2]);
    }
    else if (command == "erase")
    {
        if (userCommands[1] == "")
        {
            cerr << "Invalid path or value." << endl;
        } 
        else 
        {
            current->erase(userCommands[1]);
        }
    }
    else if (command == "move") 
    {
        if (userCommands[1] == "")
        {
            cerr << "Invalid path from" << endl;
        }
        else 
        {
            if (userCommands[2] != "") 
            {
                string temp = "";
                current->move(userCommands[1], temp);
            }
            else 
            {
                current->move(userCommands[1], userCommands[2]);
            }
        }
    }
    else if (command == "create")
    {
        if (userCommands[1] == "" && userCommands[2] == "")
        {
            cerr << "Invalid path from or new value." << endl;
        } 
        else 
        {
            current->create(userCommands[1], userCommands[2]);
        }
    }
}

Interface::~Interface() {
    delete current;
}