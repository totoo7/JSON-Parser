#include "JsonFactory.hpp"
#include "JsonObject.hpp"
#include "Utilities.hpp"
JsonObject::JsonObject() {}
JsonObject::JsonObject(const vector<JsonPair> &other)
{
    for (size_t i = 0; i < other.size(); i++)
    {
        value.push_back(other[i]);
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
    vector<JsonPair> search_values;
    bool found = false;
    for (size_t i = 0; i < value.size(); i++)
    {
        if (value[i].getKey() == key)
        {
            search_values.push_back(value[i]);
            found = true;
        } 
        else if (value[i].getValue()->search(key))
        {
            found = true;
        }
    }

    if (!found) return false;
    
    for (size_t i = 0; i < search_values.size(); i++)
    {
        search_values[i].getValue()->print();
        cout << endl;
    }
    return true;
}

bool JsonObject::containsRecursive(const string &value, const string &currentKey, vector<string> &keys) const
{
    // TODO
    return true;
}

void JsonObject::create(const string &path, const string &newValue, int depth)
{
    vector<string> tokens;
    try
    {
        tokens = UTILITIES::split(path, '/');
    }
    catch (...)
    {
        cerr << "Invalid path." << endl;
    }

    if (depth == tokens.size() - 1)
    {
        for (JsonPair &pair : value)
        {
            if (pair.getKey() == tokens.back())
            {
                cerr << "Such element already exists in this path." << endl;
                return;
            }
        }
        JsonPair temp { JsonFactory::get().parseValue(newValue), tokens.back() };
        if (temp.getValue())
        {
            value.push_back(temp);
        }
        else
        {
            cerr << "Invalid JSON syntax.";
        }
        return;
    }
    else 
    {
        for (JsonPair &pair : value)
        {
            if (pair.getKey() == tokens[depth])
            {
                pair.getValue()->create(path, newValue, depth + 1);
            }
        }
    }
}

void JsonObject::set(const string &path, const string &newValue, int depth)
{
    vector<string> tokens;
    try
    {
        tokens = UTILITIES::split(path, '/');
    }
    catch (...)
    {
        cerr << "Invalid path." << endl;
        return;
    }

    if (depth == tokens.size() - 1)
    {
        for (JsonPair &pair : value)
        {
            if (pair.getKey() == tokens[depth])
            {
                delete pair.getValue();
                Json *temp = JsonFactory::get().parseValue(newValue);
                if (temp)
                {
                    pair.setValue(temp);
                }
                else
                {
                    cerr << "Invalid JSON syntax." << endl;
                }
                return;
            }
        }
        cerr << "Invalid path." << endl;
        return;
    }
    else 
    {
        for (JsonPair &pair : value)
        {
            if (pair.getKey() == tokens[depth])
            {
                pair.getValue()->set(path, newValue, depth + 1);
                return;
            }
        }
    }
    cerr << "Invalid path." << endl;
}

void JsonObject::erase(const string &path, int depth)
{
    vector<string> tokens;
    try 
    {
        tokens = UTILITIES::split(path, '/');
    } 
    catch (...)
    {
        cerr << "Invalid path." << endl;
        return;
    }
    
    if (depth == tokens.size() - 1)
    {
        for (size_t i = 0; i < value.size(); i++)
        {
            if (value[i].getKey() == tokens[depth])
            {
                value.erase(value.begin() + i);
                return;
            }
        }
        cerr << "Invalid path." << endl;
        return;
    }
    else 
    {
        for (JsonPair &pair : value)
        {
            if (pair.getKey() == tokens[depth])
            {
                pair.getValue()->erase(path, depth + 1);
                return;
            }
        }
    }

    cerr << "Invalid path." << endl;
}

void JsonObject::move(const string &from, string &to, int depth)
{
    vector<string> tokens;
    try
    {
        tokens = UTILITIES::split(from, '/');
    }
    catch (...)
    {
        cerr << "Invalid path." << endl;
    }

    if (depth == tokens.size() - 1)
    {
        bool found = false;
        for (size_t i = 0; i < value.size(); i++) 
        {
            if (value[i].getKey() == tokens[depth])
            {
                found = true;
                if (to != "" && to[to.size() - 1] != '/') 
                {
                    to += "/";
                }
                string temp = value[i].getKey() + "\\" + value[i].getValue()->toString();
                to += temp;
                value.erase(value.begin() + i);
                break;
            }
        }
        if (!found) 
        {
            cerr << "Invalid path." << endl;
            return;
        }
    }
    for (JsonPair &pair : value) 
    {
        if (pair.getKey() == tokens[depth]) 
        {
            pair.getValue()->move(from, to, depth + 1);
        }
    }
    if (depth == 0) {
        vector<string> tokens;
        tokens = UTILITIES::split(to, '\\');
        create(tokens[0], tokens[1]);
    }
}

Json *JsonObject::clone() const
{
    return new JsonObject(value);
}
void JsonObject::print() const
{
    cout << toString();
}

string JsonObject::toString(int indentLevel) const
{
    string temp;
    string indent(indentLevel, ' ');

    temp += "{\n";

    for (size_t i = 0; i < value.size(); i++)
    {
        temp += indent + "  ";
        temp += '"';
        temp += value[i].getKey();
        temp += '"';
        temp += " : ";

        temp += value[i].getValue()->toString(indentLevel + 2);
        if (i != value.size() - 1)
            temp += ",";
        temp += "\n";
    }
    temp += indent + "}";
    return temp;
}

JsonObject::~JsonObject() {}
