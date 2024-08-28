#include "ObjectCreator.hpp"
#include "Utilities.hpp"

ObjectCreator::ObjectCreator() : JsonCreator("object") {}

bool ObjectCreator::getValue(const string &value) const
{
    return value[0] == '{';
}

Json *ObjectCreator::createJson(const string &value) const
{
    string content = UTILITIES::removeDelimeters(value, '{', '}');
    return parseObject(content);
}

Json *ObjectCreator::parseObject(const string &value) const
{
    size_t index = 0;
    vector<JsonPair> pair;
    while (index < value.length())
    {
        string key(parseObjectKey(value, index));
        string element(parser::parseValue(value, index));
        if (element.empty())
            continue;

        Json *json = JsonFactory::get().parseValue(element);
        if (json)
        {
            pair.push_back({json, key});
        }
        delete json;
    }
    return new JsonObject(pair);
}

string ObjectCreator::parseObjectKey(const string &value, size_t &index) const
{
    string key;
    bool inQuotes = false;

    for (; index < value.length(); index++)
    {
        if (value[index] == '"')
        {
            inQuotes = !inQuotes;
            if (!inQuotes)
                break;
        }
        else if (inQuotes)
        {
            key += value[index];
        }
    }

    while (index < value.length() && value[index] != ':')
    {
        index++;
    }
    if (index < value.length() && value[index] == ':')
    {
        index++;
    }
    return key;
}

static ObjectCreator creator;