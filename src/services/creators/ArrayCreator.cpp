#include "ArrayCreator.hpp"

ArrayCreator::ArrayCreator() : JsonCreator("array") {}

Json *ArrayCreator::createJson(const string &value) const
{
    string temp = JsonCreator::removeDelimeters(value, '[', ']');
    return parseArray(temp);
}

bool ArrayCreator::getValue(const string &object) const
{
    return object[0] == '[';
}

Json *ArrayCreator::parseArray(const string &value) const
{
    //TODO
    return nullptr;
}

static ArrayCreator creator;