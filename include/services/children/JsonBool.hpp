#ifndef JSON_BOOL_H
#define JSON_BOOL_H

#include "Json.hpp"

/**
 * @brief Class representing a boolean JSON value.
 *
 * This class inherits from Json and encapsulates a boolean value.
 */
class JsonBool : public Json
{
public:
  /**
   * @brief Default constructor initializing the value to false.
   */
  JsonBool();
  /**
   * @brief Constructor initializing the value with a specified boolean.
   *
   * @param value
   */
  JsonBool(const bool value);
  /**
   * @brief Copy constructor.
   *
   * @param other 
   */
  JsonBool(const JsonBool &other);
  /**
   * @brief Defines operator=
   *
   * @param other
   * @return JsonBool&
   */
  JsonBool &operator=(const JsonBool &other);
  /**
   * @brief Clones method
   *
   * @return Json*
   */
  Json *clone() const override;
  /**
   * @brief Logs the boolean value.
   */
  void print() const override;
  /**
   * @brief Checks if the boolean value equals the given string representation.
   *
   * @param value The string value to compare against ("true" or "false").
   * @return true if the value matches, false otherwise.
   */
  const bool contains(const string &value) const override;
  /**
   * @brief Converts the boolean value to a string.
   *
   * @param indentLevel The indentation level for pretty-printing (default: 0).
   * @return String representation of the boolean value ("true" or "false").
   */
  std::string toString(int indentLevel = 0) const override;

private:
  bool value;
};

#endif