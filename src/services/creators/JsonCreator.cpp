#include "JsonFactory.hpp"

JsonCreator::JsonCreator(const string &value) : value(value)
{
    JsonFactory::get().registerValidJson(this);
}

string parser::parseValue(const string &value, size_t &index) {
    string newValue;
    bool inString = false, inObject = false, inArray = false;
    size_t depth = 0;

    for (; index < value.length(); index++)
    {
        char current = value[index];

        if (current == '\r' || current == '\n')
        {
            continue;
        }
        else if (current == '\"')
        {
            newValue += '\"';
            inString = !inString;
        }
        else if (current == ' ' && !inString)
        {
            continue;
        }
        else if (current == ',' && !inString && depth == 0)
        {
            index++;
            break;
        }
        else if (current == '{')
        {
            newValue += current;
            inObject = true;
            depth++;
        }
        else if (current == '}')
        {
            newValue += current;
            depth--;
            if (depth == 0)
            {
                index++;
                break;
            }
        }
        else if (current == '[')
        {
            newValue += current;
            inArray = true;
            depth++;
        }
        else if (current == ']')
        {
            newValue += current;
            depth--;
            if (depth == 0)
            {
                index++;
                break;
            }
        }
        else
        {
            newValue += current;
        }
    }
    
    return newValue;
}