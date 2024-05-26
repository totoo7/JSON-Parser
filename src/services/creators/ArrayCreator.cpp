#include "ArrayCreator.hpp"

ArrayCreator::ArrayCreator() : JsonCreator("array") {}

Json *ArrayCreator::createJson(const string &value) const
{
    string temp = removeSquareBraces(value);
    return parseArray(temp);
}

bool ArrayCreator::getValue(const string &object) const
{
    return object[0] == '[';
}


string ArrayCreator::removeSquareBraces(const string &val) const
{
    size_t startPos = value.find("[");
    size_t endPos = value.find("]");
    string content;
    if (startPos != string::npos && endPos != string::npos)
    {
        content = value.substr(startPos + 1, endPos - startPos - 1);
    }
    return content;
}

Json *ArrayCreator::parseArray(const string &value) const
{
    //TODO
    return nullptr;
}

static ArrayCreator creator;