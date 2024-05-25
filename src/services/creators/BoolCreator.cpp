#include "BoolCreator.hpp"

BoolCreator::BoolCreator() : JsonCreator("bool") {}

Json *BoolCreator::createJson(const string &value) const
{
    return new JsonBool(stringToBool(value));
}

bool BoolCreator::getValue(const string &object) const
{
    return isBool(object);
}

bool BoolCreator::stringToBool(const string &value) const
{
    if (value == "true")
        return true;
    return false;
}

bool BoolCreator::isBool(const string &value) const
{
    if (value == "true" || value == "false") 
        return true;
    return false;
}

static BoolCreator creator;