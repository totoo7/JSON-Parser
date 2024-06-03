#ifndef STRING_CREATOR_H
#define STRING_CREATOR_H

#include "JsonCreator.hpp"
#include "JsonString.hpp"

class StringCreator : public JsonCreator
{
public:
    StringCreator();
    Json *createJson(const string &value) const override;
    bool getValue(const string &object) const override;
    ~StringCreator() = default;
};

#endif