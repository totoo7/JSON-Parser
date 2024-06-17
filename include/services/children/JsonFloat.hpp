#ifndef JSON_FLOAT_H
#define JSON_FLOAT_H

#include "Json.hpp"
/**
 * @brief Class representing a floating point JSON value.
 *
 * This class inherits from Json and encapsulates a floating point value.
 */
class JsonFloat : public Json
{
public:
  /**
   * @brief Default constructor initializing the value to 0.
   */
  JsonFloat();
  /**
   * @brief Constructor initializing the value with a specified float.
   *
   * @param value
   */
  JsonFloat(const float value);
  /**
   * @brief Copy constructor.
   *
   * @param other
   */
  JsonFloat(const JsonFloat &other);
  /**
   * @brief Defines operator=
   *
   * @param other
   * @return JsonFloat&
   */
  JsonFloat &operator=(const JsonFloat &other);
  /**
   * @brief Clone method.
   *
   * @return Json*
   */
  Json *clone() const override;
  /**
   * @brief Logs the floating point value.
   *
   */
  void print() const override;
  /**
   * @brief Checks if the floating point value equals the given string representation.
   *
   * @param value The string value to compare against.
   * @return true if the value matches, false otherwise.
   */
  const bool contains(const string &value) const override;
  /**
   * @brief Converts the floating point value to a string.
   *
   * @param indentLevel The indentation level for pretty-printing (default: 0).
   * @return String representation of the floating point value.
   */
  string toString(int indentLevel = 0) const override;
  /**
   * @brief Destroy the Json Float object.
   * Default destructor.
   */
  ~JsonFloat() = default;

private:
  float value;
};

#endif