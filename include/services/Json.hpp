#ifndef JSON_H
#define JSON_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Json
{
public:
    Json() = default;
    Json(const Json &rhs) = default;
    virtual void print() const = 0;
    virtual string toString() const = 0;
    virtual Json *clone() const = 0;
    virtual void printSearchResults() const {}
    virtual void printContainsResults() const {}
    virtual const bool search(const string &key) const;
    vector<string> contains(const string &value) const;
    virtual void create(const string &path, const string &newValue, int depth = 0) {}
    virtual void set(const string &path, const string &newValue, int depth = 0) {}
    virtual void erase(const string &path, int depth = 0) {}
    virtual void move(const string &from, string &to, int depth = 0) {}
    virtual bool printSpace() const { return false; }
    virtual bool containsRecursive(const string &value, const string &currentKey, vector<string> &keys) const = 0;
    virtual ~Json() = default;

protected:
    static size_t format_spaces;
};

#endif
