#ifndef ARRAY_CREATOR_H
#define ARRAY_CREATOR_H

#include "JsonCreator.hpp"
#include "JsonFactory.hpp"
#include "JsonArray.hpp"

class ArrayCreator : public JsonCreator
{
public:
    ArrayCreator();
    Json *createJson(const string &value) const override;
    bool getValue(const string &object) const override;
    ~ArrayCreator() = default;

private:
    Json *parseArray(const string &value) const;
};

#endif