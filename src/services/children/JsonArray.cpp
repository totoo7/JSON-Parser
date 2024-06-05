#include "JsonArray.hpp"
#include "JsonFactory.hpp"
#include "Utilities.hpp"

JsonArray::JsonArray() {}
JsonArray::JsonArray(const vector<Json*> &value)
{
    for (size_t i = 0; i < value.size(); i++) 
    {
        this->value.push_back(value[i]->clone());
    }
}

JsonArray::JsonArray(const JsonArray &other)
{
    for (size_t i = 0; i < other.value.size(); i++) 
    {
        value.push_back(other.value[i]->clone());
    }
}

JsonArray &JsonArray::operator=(const JsonArray &other)
{
    if (this == &other)
        return *this;
    for (size_t i = 0; i < other.value.size(); ++i) 
    {
        value.push_back(other.value[i]->clone());
    }
    return *this;
}

void JsonArray::print() const
{
    cout << toString();
}

string JsonArray::toString(int indentLevel) const
{
    string temp;
    temp += "[";
    for (size_t i = 0; i < value.size(); i++)
    {
        temp += value[i]->toString();  
        if (i != value.size() - 1) 
            temp += ", ";
    }
    
    temp += "]";
    return temp;
}

const bool JsonArray::search(const string &key) const
{
    for (size_t i = 0; i < value.size(); i++)
        value[i]->search(key);
    return true;
}

bool JsonArray::containsRecursive(const string &value, const string &currentKey, vector<string> &keys) const
{
    //TODO
    return true;
}

void JsonArray::create(const string &path, const string &newValue, int depth)
{
    vector<string> tokens = UTILITIES::split(path, '/');
    if (depth == tokens.size() - 1)
    {
        Json *temp =  JsonFactory::get().parseValue(newValue);
        if (temp)
        {
            value.push_back(temp->clone());
        }
        else
        {
            cerr << "Invalid JSON syntax.";
        }
        delete temp;
        return;
    }
    else 
    {
        for (Json *json : value)
        {
            json->create(path, newValue, depth + 1);            
        }
    }
}

void JsonArray::erase(const string &path, int depth)
{
    vector<string> tokens = UTILITIES::split(path, '/');
    for (Json *json : value)
    {
        json->erase(path, depth++);
    }
}

Json *JsonArray::clone() const
{
    return new JsonArray(value);
}

JsonArray::~JsonArray()
{
    for (size_t i = 0; i < value.size(); i++) 
    {
        delete value[i];
    }
}
