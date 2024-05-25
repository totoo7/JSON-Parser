#include "Json.hpp"
size_t Json::format_spaces = 0;

const bool Json::search(const string &key) const
{
    return false;
}

vector<string> Json::contains(const string &value) const
{
    vector<string> keys;
    containsRecursive(value, "", keys);
    return keys;
}