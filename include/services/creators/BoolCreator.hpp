#ifndef BOOL_CREATOR_H
#define BOOL_CREATOR_H

#include "JsonCreator.hpp"
#include "JsonBool.hpp"

class BoolCreator : public JsonCreator
{
public:
    BoolCreator();
    Json *createJson(const string &value) const override;
    bool getValue(const string &object) const override;
    ~BoolCreator() = default;
private:
    bool isBool(const string &value) const;
    bool stringToBool(const string &val) const;
};

#endif