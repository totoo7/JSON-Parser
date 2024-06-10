#include "JsonArray.hpp"
#include "JsonFactory.hpp"
#include "Utilities.hpp"

JsonArray::JsonArray() {}
JsonArray::JsonArray(const vector<Json*> &value)
{
    for (size_t i = 0; i < value.size(); i++) 
    {
        values.push_back(value[i]->clone());
    }
}

JsonArray::JsonArray(const JsonArray &other)
{
    for (size_t i = 0; i < other.values.size(); i++) 
    {
        values.push_back(other.values[i]->clone());
    }
}

JsonArray &JsonArray::operator=(const JsonArray &other)
{
    if (this == &other)
        return *this;
    for (size_t i = 0; i < other.values.size(); ++i) 
    {
        values.push_back(other.values[i]->clone());
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
    for (size_t i = 0; i < values.size(); i++)
    {
        temp += values[i]->toString(indentLevel + 2);  
        if (i != values.size() - 1) 
            temp += ", ";
    }
    temp += "]";
    return temp;
}

const bool JsonArray::search(const string &key) const
{
    for (size_t i = 0; i < values.size(); i++)
        values[i]->search(key);
    return true;
}

const bool JsonArray::contains(const string &value) const 
{
    for (size_t i = 0; i < values.size(); i++) 
    {
        if (values[i]->contains(value)) 
        {
            return true;
        }
    }
    return false;
}

void JsonArray::create(const string &path, const string &newValue, int depth)
{
    vector<string> tokens = UTILITIES::split(path, '/');
    if (depth == tokens.size() - 1)
    {
        Json *temp =  JsonFactory::get().parseValue(newValue);
        if (temp)
        {
            values.push_back(temp->clone());
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
        for (Json *json : values)
        {
            json->create(path, newValue, depth + 1);            
        }
    }
}

void JsonArray::erase(const string &path, int depth)
{
    vector<string> tokens = UTILITIES::split(path, '/');
    for (Json *json : values)
    {
        json->erase(path, depth++);
    }
}

Json *JsonArray::clone() const
{
    return new JsonArray(values);
}

JsonArray::~JsonArray()
{
    for (size_t i = 0; i < values.size(); i++) 
    {
        delete values[i];
    }
}
