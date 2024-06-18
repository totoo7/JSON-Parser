#include "JsonFactory.hpp"
#include "JsonObject.hpp"
#include "Utilities.hpp"
JsonObject::JsonObject() {}
JsonObject::JsonObject(const vector<JsonPair> &other)
{
    for (size_t i = 0; i < other.size(); i++)
    {
        pairs.push_back(other[i]);
    }
}
JsonObject::JsonObject(const JsonObject &other)
{
    for (size_t i = 0; i < other.pairs.size(); i++)
        pairs.push_back(other.pairs[i]);
}
JsonObject &JsonObject::operator=(const JsonObject &other)
{
    if (this == &other)
        pairs = other.pairs;
    return *this;
}

const bool JsonObject::search(const string &key) const
{
    vector<JsonPair> search_values;
    bool found = false;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (pairs[i].getKey() == key)
        {
            search_values.push_back(pairs[i]);
            found = true;
        }
        else if (pairs[i].getValue()->search(key))
        {
            found = true;
        }
    }

    if (!found)
        return false;
    for (size_t i = 0; i < search_values.size(); i++)
    {
        search_values[i].print();
    }
    return true;
}

void JsonObject::create(const string &path, const string &newValue, int depth)
{
    vector<string> tokens = UTILITIES::split(path, '/');
    if (depth == tokens.size() - 1)
    {
        for (JsonPair &pair : pairs)
        {
            if (pair.getKey() == tokens.back())
            {
                cerr << "Such element already exists in this path." << endl;
                return;
            }
        }
        Json *val = JsonFactory::get().parseValue(newValue);
        if (!val)
            return;
        JsonPair temp{val, tokens.back()};
        pairs.push_back(temp);
        return;
    }
    else
    {
        for (JsonPair &pair : pairs)
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
    vector<string> tokens = UTILITIES::split(path, '/');
    if (depth == tokens.size() - 1)
    {
        for (JsonPair &pair : pairs)
        {
            if (pair.getKey() == tokens[depth])
            {
                Json *temp = JsonFactory::get().parseValue(newValue);
                if (!temp)
                    return;
                delete pair.getValue();
                pair.setValue(temp);
                delete temp;
                return;
            }
        }
        cerr << "Invalid path." << endl;
        return;
    }
    else
    {
        for (JsonPair &pair : pairs)
        {
            if (pair.getKey() == tokens[depth])
            {
                pair.getValue()->set(path, newValue, depth + 1);
                return;
            }
        }
    }
}

void JsonObject::erase(const string &path, int depth)
{
    vector<string> tokens = UTILITIES::split(path, '/');
    if (depth == tokens.size() - 1)
    {
        for (size_t i = 0; i < pairs.size(); i++)
        {
            if (pairs[i].getKey() == tokens[depth])
            {
                pairs.erase(pairs.begin() + i);
                return;
            }
        }
        cerr << "Invalid path." << endl;
        return;
    }
    else
    {
        for (JsonPair &pair : pairs)
        {
            if (pair.getKey() == tokens[depth])
            {
                pair.getValue()->erase(path, depth + 1);
                return;
            }
        }
    }
}

void JsonObject::move(const string &from, string &to, int depth)
{
    vector<string> tokens = UTILITIES::split(from, '/');
    if (to == "./")
        to = "";
    if (depth == tokens.size() - 1)
    {
        bool found = false;
        for (size_t i = 0; i < pairs.size(); i++)
        {
            if (pairs[i].getKey() == tokens[depth])
            {
                found = true;
                if (to != "" && to[to.size() - 1] != '/')
                {
                    to += "/";
                }
                string temp = pairs[i].getKey() + "\\" + pairs[i].getValue()->toString();
                to += temp;
                pairs.erase(pairs.begin() + i);
                break;
            }
        }
        if (!found)
        {
            cerr << "Invalid path." << endl;
            return;
        }
    }
    for (JsonPair &pair : pairs)
    {
        if (pair.getKey() == tokens[depth])
        {
            pair.getValue()->move(from, to, depth + 1);
        }
    }
    if (depth == 0)
    {
        vector<string> tokens;
        tokens = UTILITIES::split(to, '\\');
        create(tokens[0], tokens[1], depth);
    }
}

Json *JsonObject::clone() const
{
    return new JsonObject(pairs);
}
void JsonObject::print() const
{
    cout << toString();
}

const bool JsonObject::contains(const string &value) const
{
    vector<JsonPair> contains_values;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (pairs[i].getValue()->contains(value))
        {
            /*
                This check ensures that JsonObject elements
                are not pushed to the contains_values. If the
                check is removed objects will be added and
                there will be a lot of duplicates.
            */
            if (!dynamic_cast<JsonObject *>(pairs[i].getValue()))
                contains_values.push_back(pairs[i]);
        }
    }
    if (contains_values.size() == 0)
        return false;

    for (size_t i = 0; i < contains_values.size(); i++)
    {
        contains_values[i].print();
    }
    return true;
}

string JsonObject::toString(int indentLevel) const
{
    string temp;
    string indent(indentLevel, ' ');

    temp += "{\n";

    for (size_t i = 0; i < pairs.size(); i++)
    {
        temp += indent + "  ";
        temp += '"';
        temp += pairs[i].getKey();
        temp += '"';
        temp += " : ";

        temp += pairs[i].getValue()->toString(indentLevel + 2);
        if (i != pairs.size() - 1)
            temp += ",";
        temp += "\n";
    }
    temp += indent + "}";
    return temp;
}

JsonObject::~JsonObject() {}
