#include "ObjectCreator.hpp"
ObjectCreator::ObjectCreator() : JsonCreator("object") {}

bool ObjectCreator::getValue(const string &value) const
{
    return value[0] == '{';
}

Json *ObjectCreator::createJson(const string &value) const
{
    string content = JsonCreator::removeDelimeters(value, '[', ']');
    return parseObject(value);
}

string parseValue(const string &value, size_t &index)
{
    string newValue;
    vector<char> stack;
    bool inString = false, inObject = false;

    for (; index < value.length(); index++)
    {
        char c = value[index];

        switch (c)
        {
        case '\r':
        case '\n':
            break;
        case '\"':
            if (inString)
            {
                if (!stack.empty() && stack.back() == '\"')
                {
                    inString = false;
                    stack.pop_back();
                }
            }
            else
            {
                inString = true;
                stack.push_back(c);
            }
            newValue += c;
            break;

        case ' ':
            if (!inString && !inObject)
            {
                break;
            }
            [[fallthrough]];

        case ',':
            if (!inString && !inObject && stack.empty())
            {
                index++;
                return newValue;
            }
            [[fallthrough]];

        case '{':
            if (!inString)
            {
                stack.push_back(c);
                inObject = true;
            }
            newValue += c;
            break;

        case '}':
            if (!inString && !stack.empty() && stack.back() == '{')
            {
                stack.pop_back();
                inObject = !stack.empty() && stack.back() == '{';
            }
            newValue += c;
            break;

        default:
            newValue += c;
            break;
        }
    }

    if (stack.empty())
    {
        return newValue;
    }
    else
    {
        cerr << "Invalid format" << endl;
        return "";
    }
}

Json *ObjectCreator::parseObject(const string &value) const
{
    size_t index = 0;
    vector<JsonPair> pair;
    while (index < value.length())
    {
        string key(parseObjectKey(value, index));
        string element(parseValue(value, index));
        if (element.empty())
            continue;

        Json *json = JsonFactory::get().parseValue(element);
        if (json) {
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