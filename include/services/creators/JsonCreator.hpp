#ifndef JSON_CREATOR_H
#define JSON_CREATOR_H

#include "Json.hpp"
#include "JsonPair.hpp"
class JsonCreator
{
public:
    JsonCreator(const string &value);
    virtual bool getValue(const string &object) const = 0;
    virtual Json *createJson(const string &value) const = 0;
    virtual ~JsonCreator() = default;
protected:
    static string removeDelimeters(const string& value, char openingDelimeter, char closingDelimeter);
    string value;
};

#endif