#include "JsonPair.hpp"

JsonPair::JsonPair() : value(nullptr), key("") {}

JsonPair::JsonPair(const Json *value) : key(""), value(value->clone()) {}

JsonPair::JsonPair(const Json *value, const string &key) : value(value->clone()), key(key) {}

JsonPair::JsonPair(const JsonPair &other) : value(other.value->clone()), key(other.key) {}

JsonPair &JsonPair::operator=(const JsonPair &other)
{
    if (this == &other)
        return *this;
    key = other.key;
    if (value)
        delete value;
    value = other.value->clone();
    return *this;
}

void JsonPair::print() const
{
    cout << '"' << key  << '"' << ": ";
    cout << value->toString();
    cout << endl;
}

Json *JsonPair::getValue() const
{
    return value;
}

string JsonPair::getKey() const
{
    return key;
}

void JsonPair::setValue(const Json *value)
{
    this->value = value->clone();
}

void JsonPair::setKey(const string &key)
{
    this->key = key;
}

JsonPair::~JsonPair()
{
    delete value;
}