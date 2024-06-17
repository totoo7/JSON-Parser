#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H

#include "Command.hpp"
#include <vector>
/**
 * @brief Handles commands
 *
 */
class CommandManager
{
public:
    /**
     * @brief Constructs a CommandManager object and initializes the list of commands.
     */
    CommandManager();
    /**
     * @brief Checks if a given command name is valid.
     *
     * @param name The name of the command to check.
     * @return true if the command name is valid, false otherwise.
     */
    bool isValidCommand(const string &name) const;
    /**
     * @brief Retrieves a command by name.
     *
     * @param name The name of the command to retrieve.
     * @return A pointer to the Command object if found, nullptr otherwise.
     */
    const Command *getCommand(const string &name) const;
    /**
     * @brief Converts a command name to lowercase.
     *
     * @param name The name of the command to convert.
     */
    void toLowerCase(string &name);

private:
    vector<Command> commands;
};

#endif