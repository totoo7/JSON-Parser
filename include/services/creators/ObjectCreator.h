#include "JsonCreator.h"

class ObjectCreator : public JsonCreator
{
public:
    ObjectCreator();
    Json* createJson(const string& value) const override;
    bool getValue(const string& object) const override;
    ~ObjectCreator() = default;
private:
    string removeCurlyBraces(const string& value) const;
    string parseObjectKey(const string& value, size_t& index) const;
    Json* parseObject(const string& value) const;
};

