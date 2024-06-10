#include "JsonNull.hpp"

JsonNull::JsonNull() {}
JsonNull &JsonNull::operator=(const JsonNull &other)
{
    return *this;
}

Json *JsonNull::clone() const 
{ 
    return new JsonNull(); 
}
void JsonNull::print() const
{
    cout << toString();
}
const bool JsonNull::contains(const string &value) const 
{
    if (value == "null") return true;
    return false;
}
string JsonNull::toString(int indentLevel) const
{
    return "null";
}