#ifndef JSON_NULL_H
#define JSON_NULL_H

#include "Json.hpp"

class JsonNull : public Json
{
public:
  JsonNull();
  JsonNull &operator=(const JsonNull &other);
  Json *clone() const override;
  void print() const override;
  string toString(int indentLevel = 0) const override;
  bool containsRecursive(const string &value, const string &currentKey, vector<string> &keys) const override;
  ~JsonNull() = default;
};

#endif