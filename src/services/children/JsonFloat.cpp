#include "JsonFloat.hpp"

JsonFloat::JsonFloat() : value(0) {}
JsonFloat::JsonFloat(const float value) : value(value) {}
JsonFloat::JsonFloat(const JsonFloat &other) : Json(other), value(other.value) {}
JsonFloat &JsonFloat::operator=(const JsonFloat &other)
{
    if (this == &other)
        return *this;
    value = other.value;
    return *this;
}

Json *JsonFloat::clone() const
{
    return new JsonFloat(value);
}

void JsonFloat::print() const
{
    cout << toString();
}

const bool JsonFloat::contains(const string &value) const 
{
    float temp = 0.0f;
    try 
    {
        temp = stof(value);
    } 
    catch (const invalid_argument &e)
    {
        return false;
    }
    if (temp == this->value) 
    {
        return true;
    }
    return false;
}
string JsonFloat::toString(int indentLevel) const
{
    return to_string(value).c_str();
}