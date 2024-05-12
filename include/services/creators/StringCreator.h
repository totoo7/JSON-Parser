#include "JsonCreator.h"
#include "JsonString.h"

class StringCreator : public JsonCreator
{
public:
    StringCreator();
    Json* createJson(const string& value) const override;
    bool getValue(const string& object) const override;
    ~StringCreator() = default;
private:
    bool isString(const string& value) const;
    string removeQuotes(const string &val) const;
};

