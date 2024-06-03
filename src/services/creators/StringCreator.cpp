#include "StringCreator.hpp"
#include "Utilities.hpp"

StringCreator::StringCreator() : JsonCreator("string") {}

Json *StringCreator::createJson(const string &value) const
{
    return new JsonString(UTILITIES::removeDelimeters(value, '"', '"'));
}

bool StringCreator::getValue(const string &object) const
{
    return object[0] == '"' && object[object.length() - 1] == '"';
}

static StringCreator creator;