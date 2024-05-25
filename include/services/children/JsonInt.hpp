#ifndef JSON_INT_H
#define JSON_INT_H

#include "Json.hpp"

class JsonInt : public Json
{
public:
  JsonInt();
  JsonInt(const int value);
  JsonInt(const JsonInt &other);
  JsonInt &operator=(const JsonInt &other);
  Json *clone() const override;
  void print() const override;
  string toString() const override;
  bool containsRecursive(const string &value, const string &currentKey, vector<string> &keys) const override;
  ~JsonInt() = default;

private:
  int value;
};

#endif