#include "StringCreator.hpp"

StringCreator::StringCreator() : JsonCreator("string") {}

Json *StringCreator::createJson(const string &value) const
{
    return new JsonString(JsonCreator::removeDelimeters(value, '"', '"'));
}

bool StringCreator::isString(const string &value) const
{
    return value[0] == '"' && value[value.length() - 1] == '"';
}

bool StringCreator::getValue(const string &object) const
{
    return isString(object);
}

static StringCreator creator;