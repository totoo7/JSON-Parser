#include "StringCreator.h"

StringCreator::StringCreator() : JsonCreator("string") {}

Json *StringCreator::createJson(const string &value) const
{
    return new JsonString(removeQuotes(value));
}

bool StringCreator::isString(const string &value) const
{
    if (value[0] == '"' && value[value.length() - 1] == '"')
        return true;
    return false;
}

bool StringCreator::getValue(const string &object) const
{
    cout << object;
    return isString(object);
}

string StringCreator::removeQuotes(const string &value) const
{
    size_t startPos = value.find('"');
    size_t endPos = value.find('"');
    string content;
    if (startPos != string::npos && endPos != string::npos)
    {
        content = value.substr(startPos + 1, endPos - startPos - 1);
    }
    return content;
}

static StringCreator creator;