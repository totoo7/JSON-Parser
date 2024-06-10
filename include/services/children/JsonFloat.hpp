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
  const bool contains(const string &value) const override;
  string toString(int indentLevel = 0) const override;
  ~JsonFloat() = default;

private:
  float value;
};

#endif