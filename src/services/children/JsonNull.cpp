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

bool JsonNull::containsRecursive(const string &value, const string &currentKey, vector<string> &keys) const
{
    //TODO
    return true;
}

string JsonNull::toString(int indentLevel) const
{
    return "null";
}