#include "JsonPair.h"

JsonPair::JsonPair() : value(nullptr), key("") {}

JsonPair::JsonPair(const Json* value) : key("")
{
    value = value->clone();
}

JsonPair::JsonPair(const Json* value, const string& key)
{
    value = value->clone();
    this->key = key;
}

JsonPair::JsonPair(const JsonPair& other) : value(other.value->clone()), key(other.key) {}

JsonPair& JsonPair::operator=(const JsonPair& other)
{
    if (this == &other) return *this;
    key = other.key;
    if (value) delete value;
    value = other.value->clone();
    return *this;
}

JsonPair::~JsonPair() 
{ 
    delete value; 
}