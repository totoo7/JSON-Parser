#ifndef FLOAT_CREATOR_H
#define FLOAT_CREATOR_H

#include "JsonCreator.hpp"
#include "JsonFloat.hpp"

class FloatCreator : public JsonCreator
{
public:
    FloatCreator();
    Json *createJson(const string &value) const override;
    bool getValue(const string &object) const override;
    ~FloatCreator() = default;
private:
    bool isFloat(const string &value) const;
    int stringToFloat(const string &val) const;
};

#endif