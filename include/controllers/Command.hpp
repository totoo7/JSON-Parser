#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
using namespace std;
/**
 * @brief Simple command class.
 */
class Command
{
public:
    /**
     * @brief Constructs a Command object with a name and parameter count.
     *
     * @param name The name of the command.
     * @param paramCount The number of parameters the command takes.
     */
    Command(const string &name, size_t paramCount);
    /**
     * @brief Gets the name of the command.
     *
     */
    string getName() const;
    /**
     * @brief Gets the number of parameters of the command.
     *
     */
    size_t getParamCount() const;

private:
    string name;
    size_t paramCount;
};

#endif