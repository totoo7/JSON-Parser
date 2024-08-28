#ifndef BOOL_CREATOR_H
#define BOOL_CREATOR_H

#include "JsonCreator.hpp"
#include "JsonBool.hpp"
/**
 * @class BoolCreator
 * @brief A concrete implementation of JsonCreator that handles the creation of boolean JSON values.
 */
class BoolCreator : public JsonCreator
{
public:
    /**
     * @brief Construct a new BoolCreator object.
     * Initializes the JsonCreator's value as "bool" with it's constructor.
     */
    BoolCreator();
    /**
     * @brief Creates a JsonBool.
     *
     * @param value
     * @return Json*
     */
    Json *createJson(const string &value) const override;
    /**
     * @brief Get the value object.
     *
     * @param object
     * @return true if the passed value is either "true" or "false", false otherwise.
     */
    bool getValue(const string &object) const override;
    /**
     * @brief Destroy the Bool Creator object.
     * Default destructor.
     */
    ~BoolCreator() = default;

private:
    /**
     * @brief Checks if passed value is a boolean.
     *
     * @param value
     * @return true if the passed value can be parsed to bool, false otherwise.
     */
    bool isBool(const string &value) const;
    /**
     * @brief Makes a bool from a string value.
     *
     * @param val
     * @return true if passed val is true, false otherwise.
     */
    bool stringToBool(const string &val) const;
};

#endif