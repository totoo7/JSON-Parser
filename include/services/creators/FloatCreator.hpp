#ifndef FLOAT_CREATOR_H
#define FLOAT_CREATOR_H

#include "JsonCreator.hpp"
#include "JsonFloat.hpp"

/**
 * @class FloatCreator
 * @brief A concrete implementation of JsonCreator that handles the creation of floating JSON values.
 */
class FloatCreator : public JsonCreator
{
public:
    /**
     * @brief Construct a new FloatCreator object.
     * Initializes the JsonCreator's value as "float" with it's constructor.
     */
    FloatCreator();
    /**
     * @brief Creates a JsonFloat.
     *
     * @param value
     * @return Json*
     */
    Json *createJson(const string &value) const override;
    /**
     * @brief Get the value object.
     *
     * @param object
     * @return true if the passed value is a valid float value, false otherwise.
     */
    bool getValue(const string &object) const override;
    /**
     * @brief Destroy the Float Creator object.
     * Default destructor.
     */
    ~FloatCreator() = default;

private:
    /**
     * @brief Checks if a string represents a valid floating point number.
     *
     * This method verifies if the given string contains characters consistent with a
     * floating point number. It checks for the presence of a decimal point ('.') and
     * allows for optional sign characters ('-' or '+'). The method further ensures that
     * the remaining characters are digits or valid components of a floating point number.
     *
     * @param value The string to be checked.
     * @return true if the string represents a valid floating point number, false otherwise.
     */
    bool isFloat(const string &value) const;
};

#endif