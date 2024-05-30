#include "JsonString.hpp"

JsonString::JsonString() : value("") {}

JsonString::JsonString(const string value) : value(value) {}

JsonString::JsonString(const JsonString &other) : Json(other), value(other.value) {}

JsonString &JsonString::operator=(const JsonString &other)
{
    if (this == &other)
        return *this;
    value = other.value;
    return *this;
}

Json *JsonString::clone() const
{
    return new JsonString(value);
}

bool JsonString::containsRecursive(const string &value, const string &currentKey, vector<string> &keys) const
{
    return true;
    // TODO
}

string JsonString::toString(int indentLevel) const
{
    string temp;
    temp += "\"";
    temp += value;
    temp += "\"";
    return temp;
}

void JsonString::print() const
{
    cout << toString();
}
