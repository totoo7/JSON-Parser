#ifndef JSON_BOOL_H
#define JSON_BOOL_H

#include "Json.hpp"

class JsonBool : public Json
{
public:
  JsonBool();
  JsonBool(const bool value);
  JsonBool(const JsonBool &other);
  JsonBool &operator=(const JsonBool &other);
  Json *clone() const override;
  void print() const override;
  const bool contains(const string &value) const override;
  string toString(int indentLevel = 0) const override;
  ~JsonBool() = default;

private:
  bool value;
};

#endif