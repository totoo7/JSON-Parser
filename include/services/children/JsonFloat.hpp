#ifndef JSON_FLOAT_H
#define JSON_FLOAT_H

#include "Json.hpp"

class JsonFloat : public Json
{
public:
  JsonFloat();
  JsonFloat(const float value);
  JsonFloat(const JsonFloat &other);
  JsonFloat &operator=(const JsonFloat &other);
  Json *clone() const override;
  void print() const override;
  string toString() const override;
  bool containsRecursive(const string &value, const string &currentKey, vector<string> &keys) const override;
  ~JsonFloat() = default;

private:
  float value;
};

#endif