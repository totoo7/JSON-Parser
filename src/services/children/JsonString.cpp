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

string JsonString::toString(int indentLevel) const
{
    string temp;
    temp += "\"";
    temp += value;
    temp += "\"";
    return temp;
}

const bool JsonString::contains(const string &value) const  
{
    return this->value.find(value) != string::npos;
}

void JsonString::print() const
{
    cout << toString();
}
