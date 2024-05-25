#ifndef JSON_STRING_H
#define JSON_STRING_H

#include "Json.hpp"

class JsonString : public Json
{
public:
  JsonString();
  JsonString(const string value);
  JsonString(const JsonString &other);
  JsonString &operator=(const JsonString &other);
  Json *clone() const override;
  void print() const override;
  string toString() const override;
  bool containsRecursive(const string &value, const string &currentKey, vector<string> &keys) const override;
  ~JsonString() = default;

private:
  string value;
};

#endif