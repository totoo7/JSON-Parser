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
const bool JsonBool::contains(const string &value) const 
{
    if (value == "true" && this->value == true) 
    {
        return true;
    } else if (value == "false" && this->value == false) 
    {
        return true;
    }
    return false;
}

string JsonBool::toString(int indentLevel) const
{
    if (value) {
        return "true";
    } 
    return "false";
}