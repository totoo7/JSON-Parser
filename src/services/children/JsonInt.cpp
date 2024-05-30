#include "JsonInt.hpp"

JsonInt::JsonInt() : value(0) {}
JsonInt::JsonInt(const int value) : value(value) {}
JsonInt::JsonInt(const JsonInt &other) : Json(other), value(other.value) {}
JsonInt &JsonInt::operator=(const JsonInt &other)
{
    if (this == &other)
        return *this;
    value = other.value;
    return *this;
}

Json *JsonInt::clone() const
{
    return new JsonInt(value);
}

void JsonInt::print() const
{
    cout << toString();
}

bool JsonInt::containsRecursive(const string &value, const string &currentKey, vector<string> &keys) const
{
    //TODO
    return true;
}

string JsonInt::toString(int indentLevel) const
{
    return to_string(value).c_str();
}