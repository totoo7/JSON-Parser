#include "IntCreator.hpp"

IntCreator::IntCreator() : JsonCreator("int") {}

Json *IntCreator::createJson(const string &value) const
{
    return new JsonInt(stringToInt(value));
}

bool IntCreator::getValue(const string &object) const
{
    return isInt(object);
}

int IntCreator::stringToInt(const string &value) const
{
    return stoi(value);
}

bool IntCreator::isInt(const string &value) const
{
    for (size_t i = 0; i < value.length(); i++)
        if (!isdigit(value[i]) && value[i] != '-' && value[i] != '+')
            return false;
    return true;
}

static IntCreator creator;