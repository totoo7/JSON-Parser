#ifndef JSON_INT_H
#define JSON_INT_H

#include "Json.hpp"

/**
 * @brief Class representing an integer JSON value.
 *
 * This class inherits from Json and encapsulates an integer value.
 */
class JsonInt : public Json
{
public:
  /**
   * @brief Default constructor initializing the value to 0.
   */
  JsonInt();
  /**
   * @brief Constructor initializing the value with a specified integer.
   *
   * @param value The integer value to initialize with.
   */
  JsonInt(const int value);
  /**
   * @brief Copy constructor.
   *
   * @param other
   */
  JsonInt(const JsonInt &other);
  /**
   * @brief Defines operator=.
   *
   * @param other
   * @return JsonInt&
   */
  JsonInt &operator=(const JsonInt &other);
  /**
   * @brief Clones method
   *
   * @return JsonInt*
   */
  Json *clone() const override;
  /**
   * @brief Logs the integer value.
   *
   */
  void print() const override;
  /**
   * @brief Checks if the integer value equals the given string representation.
   *
   * @param value The string value to compare against.
   * @return true if the value matches, false otherwise.
   */
  const bool contains(const string &value) const override;
  /**
   * @brief Converts the integer value to a string.
   *
   * @param The indentation level for pretty-printing (default: 0).
   * @return String representation of the integer value.
   */
  string toString(int indentLevel = 0) const override;

private:
  int value;
};
#endif