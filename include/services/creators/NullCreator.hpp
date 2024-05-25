#ifndef NULL_CREATOR_H
#define NULL_CREATOR_H

#include "JsonCreator.hpp"
#include "JsonNull.hpp"

class NullCreator : public JsonCreator
{
public:
    NullCreator();
    Json *createJson(const string &value) const override;
    bool getValue(const string &object) const override;
    ~NullCreator() = default;
};

#endif