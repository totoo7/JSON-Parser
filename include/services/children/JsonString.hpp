#ifndef JSON_STRING_H
#define JSON_STRING_H

#include "Json.hpp"

/**
 * @brief Class representing a string JSON value.
 *
 * This class inherits from Json and encapsulates a string value.
 */
class JsonString : public Json
{
public:
  /**
   * @brief Default constructor initializing the value to an empty string.
   */
  JsonString();
  /**
   * @brief Constructor initializing the value with a specified string.
   *
   * @param value
   */
  JsonString(const string value);
  /**
   * @brief Copy constructor.
   *
   * @param other
   */
  JsonString(const JsonString &other);
  /**
   * @brief Defines operator=
   *
   * @param other
   * @return JsonString&
   */
  JsonString &operator=(const JsonString &other);
  /**
   * @brief Clone method.
   *
   * @return JsonString*
   */
  Json *clone() const override;
  /**
   * @brief Converts the string value to a string representation.
   *
   * @param indentLevel The indentation level for pretty-printing (default: 0).
   * @return String representation of the string value enclosed in double quotes.
   */
  string toString(int indentLevel = 0) const override;
  /**
   * @brief Checks if the string value contains the specified substring.
   *
   * @param value The substring to search for.
   * @return true if the substring is found within the string value, false otherwise.
   */
  const bool contains(const string &value) const override;
  /**
   * @brief Logs the string value.
   *
   */
  void print() const override;

private:
  string value;
};

#endif