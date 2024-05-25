#ifndef JSON_PAIR_H
#define JSON_PAIR_H
#include "Json.hpp"

class JsonPair
{
public:
    JsonPair();
    JsonPair(const Json *value);
    JsonPair(const Json *value, const string &key);
    JsonPair(const JsonPair &other);
    JsonPair &operator=(const JsonPair &other);
    ~JsonPair();

private:
    Json *value;
    string key;
};

#endif
