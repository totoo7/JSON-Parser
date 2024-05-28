#ifndef INT_CREATOR_H
#define INT_CREATOR_H

#include "JsonCreator.hpp"
#include "JsonInt.hpp"

class IntCreator : public JsonCreator
{
public:
    IntCreator();
    Json *createJson(const string &value) const override;
    bool getValue(const string &object) const override;
    ~IntCreator() = default;
private:
    bool isInt(const string &value) const;
};

#endif