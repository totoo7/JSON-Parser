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

bool JsonFloat::containsRecursive(const string &value, const string &currentKey, vector<string> &keys) const
{
    //TODO
    return true;
}

string JsonFloat::toString() const
{
    return to_string(value).c_str();
}