#ifndef INT_CREATOR_H
#define INT_CREATOR_H

#include "JsonCreator.hpp"
#include "JsonInt.hpp"
/**
 * @class IntCreator
 * @brief A concrete implementation of JsonCreator that handles the creation of integer JSON values.
 */
class IntCreator : public JsonCreator
{
public:
    /**
     * @brief Construct a new IntCreator object.
     * Initializes the JsonCreator's value as "int" with it's constructor.
     */
    IntCreator();
    /**
     * @brief Creates a JsonInt.
     *
     * @param value
     * @return Json*
     */
    Json *createJson(const string &value) const override;
    /**
     * @brief Get the value object.
     *
     * @param object
     * @return true if the passed value is a valid integer value, false otherwise.
     */
    bool getValue(const string &object) const override;
    /**
     * @brief Destroy the IntCreator object.
     * Default destructor.
     */
    ~IntCreator() = default;

private:
    /**
     * @brief Checks if a string represents a valid integer.
     *
     * This method verifies if the given string contains characters consistent with an
     * integer. It allows for optional sign characters ('-' or '+') followed by digits.
     *
     * @param value The string to be checked.
     * @return true if the string represents a valid integer, false otherwise.
     */
    bool isInt(const string &value) const;
};

#endif