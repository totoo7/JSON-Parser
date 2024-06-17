#ifndef JSON_NULL_H
#define JSON_NULL_H

#include "Json.hpp"
/**
 * @brief Class representing a JSON null value.
 *
 * This class inherits from Json and represents a null value in JSON format.
 */
class JsonNull : public Json
{
public:
  /**
   * @brief Default constructor.
   */
  JsonNull();
  /**
   * @brief Defines operator=
   *
   * @param other
   * @return JsonNull&
   */
  JsonNull &operator=(const JsonNull &other);
  /**
   * @brief Clone method.
   *
   * @return JsonNull*
   */
  Json *clone() const override;
  /**
   * @brief Logs the null value.
   *
   */
  void print() const override;
  /**
   * @brief Checks if the JSON null value contains the given string representation.
   *
   * @param value The string value to compare against ("null").
   * @return true if the value matches "null", false otherwise.
   */
  const bool contains(const string &value) const override;
  /**
   * @brief Converts the JSON null value to a string.
   *
   * @param indentLevel The indentation level for pretty-printing (default: 0).
   * @return String representation of the JSON null value ("null").
   */
  string toString(int indentLevel = 0) const override;
};

#endif