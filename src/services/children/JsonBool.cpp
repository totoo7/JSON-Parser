#include "JsonBool.hpp"

JsonBool::JsonBool() : value(false) {}
JsonBool::JsonBool(const bool value) : value(value) {}
JsonBool::JsonBool(const JsonBool &other) : Json(other), value(other.value) {}
JsonBool &JsonBool::operator=(const JsonBool &other)
{
    if (this == &other)
        return *this;
    value = other.value;
    return *this;
}

Json *JsonBool::clone() const
{
    return new JsonBool(value);
}

void JsonBool::print() const
{
    cout << toString();
}

bool JsonBool::containsRecursive(const string &value, const string &currentKey, vector<string> &keys) const
{
    //TODO
    return true;
}

string JsonBool::toString(int indentLevel) const
{
    if (value) {
        return "true";
    } 
    return "false";
}