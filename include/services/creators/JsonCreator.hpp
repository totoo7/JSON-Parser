#ifndef JSON_CREATOR_H
#define JSON_CREATOR_H

#include "JsonPair.hpp"

/**
 * @brief Base class for all creators.
 *
 */
class JsonCreator
{
public:
    /**
     * @brief Construct a new Json Creator object.
     * @param value The creator's identifier.
     */
    JsonCreator(const string &value);
    /**
     * @brief Get value object. The derived classes attempt to recognize the passed value parameter.
     *
     * Pure virtual method. This method must be implemented by all derived classes for it's own JSON type.
     *
     * @param object
     * @return true if passed object is recognized, false otherwise.
     */
    virtual bool getValue(const string &object) const = 0;
    /**
     * @brief Attempts to create a new Json object.
     *
     * Pure virtual method. This method must be implemented by all derived classes for it's own JSON type.
     *
     * @param value The value that will be parsed.
     * @return Json* The value returned as a Json pointer.
     */
    virtual Json *createJson(const string &value) const = 0;
    /**
     * @brief Destroy the Json Creator object.
     * Default destructor.
     */
    virtual ~JsonCreator() = default;

protected:
    string value;
};

/**
 * @brief Parses a JSON value from a string.
 *
 * This function extracts a single JSON value from the given string, starting at the position indicated by the `index` parameter.
 * It handles JSON objects, arrays, strings, numbers, booleans, and null values. The function updates the `index` to point to the
 * next character after the parsed value.
 *
 * @param value The JSON string from which to parse the value.
 * @param index A reference to the current position in the string. This is updated as the function parses the value.
 * @return A string containing the parsed JSON value.
 */
namespace parser
{
    string parseValue(const string &value, size_t &index);
};

#endif