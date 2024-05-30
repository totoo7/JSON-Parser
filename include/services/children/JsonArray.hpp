#ifndef JSON_ARRAY_H
#define JSON_ARRAY_H

#include "Json.hpp"

class JsonArray : public Json
{
public:
    JsonArray();
    JsonArray(const vector<Json*> &value);
    JsonArray(const JsonArray &other);
    JsonArray &operator=(const JsonArray &other);
    const bool search(const string &key) const override;
    Json *clone() const override;
    void print() const override;
    string toString(int indentLevel = 0) const override;
    bool containsRecursive(const string &value, const string &currentKey, vector<string> &keys) const override;
    void create(const string &path, const string &newValue, int depth = 0) override;
    virtual void erase(const string &path, int depth = 0) override;
    ~JsonArray();
private:
    vector<Json*> value;
};

#endif
