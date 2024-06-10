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
  const bool contains(const string &value) const override;
  string toString(int indentLevel = 0) const override;
  ~JsonString() = default;

private:
  string value;
};

#endif