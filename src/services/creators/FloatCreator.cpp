#include "FloatCreator.hpp"

FloatCreator::FloatCreator() : JsonCreator("float") {}

Json *FloatCreator::createJson(const string &value) const
{
    return new JsonFloat(stof(value));
}

bool FloatCreator::getValue(const string &object) const
{
    return isFloat(object);
}

bool FloatCreator::isFloat(const string &value) const
{
    if (value.find('.') == string::npos) return false;
    for (size_t i = 0; i < value.length(); i++) 
    {
        if (!isdigit(value[i]) && value[i] != '.' && value[i] != '-' && value[i] != '+')
            return false;
    }
    return true;
}

static FloatCreator creator;