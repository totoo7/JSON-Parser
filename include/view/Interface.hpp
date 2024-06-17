#ifndef INTERFACE_H
#define INTERFACE_H

#include "JsonFactory.hpp"
#include "CommandManager.hpp"
/**
 * @brief Basic terminal interface.
 */
class Interface
{
public:
    /**
     * @brief Constructs a new Interface object.
     */
    Interface();
    /**
     * @brief Runs the interface loop to process user commands.
     */
    void run();
    /**
     * @brief Updates the interface by processing user input.
     */
    void update();
    /**
     * @brief Processes the user input.
     *
     * @param userInput The user input.
     */
    void processUserInput(const string &userInput);
    /**
     * @brief Opens a JSON file and parses its content.
     *
     * @param filename The name of the file to open.
     * @return true if the file is successfully opened and parsed, false otherwise.
     */
    bool openFile(const string &filename);
    /**
     * @brief Saves the current JSON content to a specified path.
     *
     * @param path The path to save the file.
     * @param newFilename The name of the new file.
     */
    void saveAs(const string &path, string &newFilename);
    /**
     * @brief Saves the current JSON content to the opened file.
     */
    void save() const;
    /**
     * @brief Prints the command menu.
     */
    void printMenu() const;
    ~Interface();

private:
    bool isRunning;
    string filename;
    bool isLoadedFile;
    Json *json;
    CommandManager manager;
};

#endif