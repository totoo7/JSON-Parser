#ifndef CONTROLLER_H
#define CONROLLER_H

#include "validator.hpp"
#include "JsonFactory.hpp"

class Controller
{
public:
    static void processUserInput(const string &userInput);
};

#endif