#include "JsonFactory.hpp"
#include "JsonObject.hpp"

JsonObject::JsonObject() {}
JsonObject::JsonObject(const vector<JsonPair> &other)
{
    for (size_t i = 0; i < other.size(); i++)
        value.push_back(other[i]);
    
    for (int i = 0; i < other.size(); i++) {
        value[i].print();
    }
}
JsonObject::JsonObject(const JsonObject &other)
{
    for (size_t i = 0; i < other.value.size(); i++)
        value.push_back(other.value[i]);
}
JsonObject &JsonObject::operator=(const JsonObject &other)
{
    if (this == &other)
    value = other.value;
    return *this;
}

const bool JsonObject::search(const string &key) const
{
    //TODO
    return true;
}

void JsonObject::printSearchResults() const
{
    //TODO
}

bool JsonObject::containsRecursive(const string &value, const string &currentKey, vector<string> &keys) const
{
    //TODO
    return true;
}

void JsonObject::create(const string &path, const string &newValue, int depth)
{
    //TODO
}

void JsonObject::set(const string &path, const string &newValue, int depth)
{
   //TODO
}

void JsonObject::erase(const string &path, int depth)
{
    //TODO
}

void JsonObject::move(const string &from, string &to, int depth)
{
    //TODO
}

Json *JsonObject::clone() const { 
    return new JsonObject(value); 
}
void JsonObject::print() const
{
    cout << toString();
}

string JsonObject::toString() const
{
    //TODO
    return "string";
}

JsonObject::~JsonObject() {}
