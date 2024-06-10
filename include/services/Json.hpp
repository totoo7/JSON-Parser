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
    virtual string toString(int indentLevel = 0) const = 0;
    virtual Json *clone() const = 0;
    virtual const bool search(const string &key) const;
    virtual const bool contains(const string &value) const = 0;
    virtual void create(const string &path, const string &newValue, int depth = 0) {}
    virtual void set(const string &path, const string &newValue, int depth = 0) {}
    virtual void erase(const string &path, int depth = 0) {}
    virtual void move(const string &from, string &to, int depth = 0) {}
    virtual ~Json() = default;
};

#endif
