#include "ArrayCreator.hpp"
#include "Utilities.hpp"

ArrayCreator::ArrayCreator() : JsonCreator("array") {}

Json *ArrayCreator::createJson(const string &value) const
{
    string temp = UTILITIES::removeDelimeters(value, '[', ']');
    return parseArray(temp);
}

bool ArrayCreator::getValue(const string &object) const
{
    return object[0] == '[';
}

Json *ArrayCreator::parseArray(const string &value) const
{
    size_t index = 0;
    vector<Json*> values;
    while (index < value.length())
    {
        string element = parser::parseValue(value, index);
        Json *temp = JsonFactory::get().parseValue(element);
        values.push_back(temp->clone());
        delete temp;
    }
    Json *array = new JsonArray(values);
    for (size_t i = 0; i < values.size(); ++i)
        delete values[i];
    return array;
}

static ArrayCreator creator;