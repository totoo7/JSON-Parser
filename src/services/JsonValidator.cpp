#include "JsonValidator.hpp"

JsonValidator::JsonValidator(const string &json) : json(json), pos(0) {}

bool JsonValidator::validate()
{
    skipWhitespace();
    if (!parseValue())
    {
        return false;
    }
    skipWhitespace();
    return pos == json.length();
}

string JsonValidator::getErrorMessage() const
{
    return errorMessage;
}

void JsonValidator::skipWhitespace()
{
    while (pos < json.length() && isWhitespace(json[pos]))
    {
        pos++;
    }
}

bool JsonValidator::isWhitespace(char c)
{
    return c == ' ' || c == '\n' || c == '\r' || c == '\t';
}

bool JsonValidator::match(char expected)
{
    if (pos < json.length() && json[pos] == expected)
    {
        pos++;
        return true;
    }
    return false;
}

bool JsonValidator::parseValue()
{
    skipWhitespace();
    if (pos >= json.length())
    {
        setError("Unexpected end of input while expecting a value");
        return false;
    }

    char current = json[pos];

    if (current == '"')
        return parseString();
    if (current == '{')
        return parseObject();
    if (current == '[')
        return parseArray();
    if (current == 't' || current == 'f' || current == 'n')
        return parseLiteral();
    if (current == '-' || isDigit(current))
        return parseNumber();

    setError("Invalid value");
    return false;
}

bool JsonValidator::parseObject()
{
    if (!match('{'))
    {
        setError("Expected '{' at the beginning of object");
        return false;
    }

    skipWhitespace();
    if (match('}'))
    {
        return true; // Empty object
    }

    while (true)
    {
        skipWhitespace();
        if (!parseString())
        {
            setError("Expected string as key in object");
            return false;
        }

        skipWhitespace();
        if (!match(':'))
        {
            setError("Expected ':' after key in object");
            return false;
        }

        skipWhitespace();
        if (!parseValue())
        {
            setError("Expected value after ':' in object");
            return false;
        }

        skipWhitespace();
        if (match('}'))
        {
            return true;
        }
        else if (match(','))
        {
            continue;
        }
        else
        {
            setError("Expected ',' or '}' in object");
            return false;
        }
    }
}

bool JsonValidator::parseArray()
{
    if (!match('['))
    {
        setError("Expected '[' at the beginning of array");
        return false;
    }

    skipWhitespace();
    if (match(']'))
    {
        return true; // Empty array
    }

    while (true)
    {
        skipWhitespace();
        if (!parseValue())
        {
            setError("Expected value in array");
            return false;
        }

        skipWhitespace();
        if (match(']'))
        {
            return true;
        }
        else if (match(','))
        {
            continue;
        }
        else
        {
            setError("Expected ',' or ']' in array");
            return false;
        }
    }
}

bool JsonValidator::parseString()
{
    if (!match('"'))
    {
        setError("Expected '\"' at the beginning of string");
        return false;
    }

    while (pos < json.length())
    {
        char current = json[pos];

        if (current == '"')
        {
            pos++;
            return true;
        }
        else if (current == '\\')
        {
            pos++;
            if (pos >= json.length())
            {
                setError("Unexpected end of input in string escape sequence");
                return false;
            }
            if (!parseEscapeCharacter())
            {
                return false;
            }
        }
        else if (current < 0x20)
        { // Control characters are invalid in strings
            setError("Invalid control character in string");
            return false;
        }
        else
        {
            pos++;
        }
    }

    setError("Unexpected end of input while parsing string");
    return false;
}

bool JsonValidator::parseEscapeCharacter()
{
    char escape = json[pos];
    switch (escape)
    {
    case '"':
    case '\\':
    case '/':
    case 'b':
    case 'f':
    case 'n':
    case 'r':
    case 't':
        pos++;
        return true;
    case 'u':
        return parseUnicode();
    default:
        setError("Invalid escape character in string");
        return false;
    }
}

bool JsonValidator::parseUnicode()
{
    pos++;
    for (int i = 0; i < 4; ++i)
    {
        if (pos >= json.length() || !isHexDigit(json[pos]))
        {
            setError("Invalid unicode escape sequence in string");
            return false;
        }
        pos++;
    }
    return true;
}

bool JsonValidator::isHexDigit(char c)
{
    return isDigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

bool JsonValidator::isDigit(char c)
{
    return c >= '0' && c <= '9';
}

bool JsonValidator::parseNumber()
{
    size_t start = pos;

    if (match('-'))
    {
        if (pos >= json.length())
        {
            setError("Unexpected end of input after '-' in number");
            return false;
        }
    }

    if (match('0'))
    {
        // no digits allowed after 0
        if (pos < json.length() && isDigit(json[pos]))
        {
            setError("Leading zeros are not allowed in number");
            return false;
        }
    }
    else if (isDigit(json[pos]))
    {
        while (pos < json.length() && isDigit(json[pos]))
        {
            pos++;
        }
    }
    else
    {
        setError("Invalid number format");
        return false;
    }

    if (match('.'))
    {
        if (pos >= json.length() || !isDigit(json[pos]))
        {
            setError("Expected digits after decimal point in number");
            return false;
        }
        while (pos < json.length() && isDigit(json[pos]))
        {
            pos++;
        }
    }

    if (json[pos] == 'e' || json[pos] == 'E')
    {
        pos++;
        if (json[pos] == '+' || json[pos] == '-')
        {
            pos++;
        }
        if (pos >= json.length() || !isDigit(json[pos]))
        {
            setError("Expected digits after exponent in number");
            return false;
        }
        while (pos < json.length() && isDigit(json[pos]))
        {
            pos++;
        }
    }

    return true;
}

bool JsonValidator::parseLiteral()
{
    if (json.compare(pos, 4, "true") == 0)
    {
        pos += 4;
        return true;
    }
    else if (json.compare(pos, 5, "false") == 0)
    {
        pos += 5;
        return true;
    }
    else if (json.compare(pos, 4, "null") == 0)
    {
        pos += 4;
        return true;
    }
    setError("Invalid literal value");
    return false;
}

void JsonValidator::setError(const string &message)
{
    errorMessage = message + " at position " + to_string(pos);
}