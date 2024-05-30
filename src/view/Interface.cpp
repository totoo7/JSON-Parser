#include "Interface.hpp"

Interface::Interface() : current(nullptr), isRunning(true), filename("Null"), isLoadedFile(false) {}

bool Interface::openFile(const string &filename)
{
    if (current) delete current;
    try
    {
        current = JsonFactory::get().parseFile(filename);
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what();
        return false;
    }
    this->filename = filename;
    isLoadedFile = static_cast<bool>(current);
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

    cout << ">Enter 'open' then 'filename'' to open a new file." << endl;
    cout << ">Enter 'exit' to quit." << endl;
    if (isLoadedFile) 
    {
        cout << ">Enter 'parse' to parse and print the loaded file." << endl;
        cout << ">Enter 'save' to save the loaded file." << endl;
        cout << ">Enter 'saveas' then 'path' and 'filename' to save the loaded file to a new location" << endl;
    }
}

void Interface::processUserInput(const string& userInput) {
    vector<string> userCommands = Validator::splitCommand(userInput, ' ');
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
    // TODO etc
}

Interface::~Interface() {
    delete current;
}