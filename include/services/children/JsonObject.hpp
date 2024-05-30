#ifndef JSON_OBJECT_H
#define JSON_OBJECT_H

#include "Json.hpp"
#include "JsonPair.hpp"
class JsonObject : public Json
{
public:
    JsonObject();
    JsonObject(const vector<JsonPair> &value);
    JsonObject(const JsonObject &other);
    JsonObject &operator=(const JsonObject &other);
    const bool search(const string &key) const override;
    void create(const string &path, const string &newValue, int depth = 0) override;
    virtual void set(const string &path, const string &newValue, int depth = 0) override;
    virtual void erase(const string &path, int depth = 0) override;
    virtual void move(const string &from, string &to, int depth = 0) override;
    Json *clone() const override;
    void print() const override;
    void printSearchResults() const override;
    string toString(int indentLevel = 0) const override;
    ~JsonObject();
protected:
    bool containsRecursive(const string &value, const string &currentKey, vector<string> &keys) const override;
private:
    vector<JsonPair> value;
};

#endif 
