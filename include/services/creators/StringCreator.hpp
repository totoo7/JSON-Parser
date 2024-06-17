#ifndef STRING_CREATOR_H
#define STRING_CREATOR_H

#include "JsonCreator.hpp"
#include "JsonString.hpp"

class StringCreator : public JsonCreator
{
public:
    /**
     * @brief Construct a new StringCreator object.
     * Initializes the JsonCreator's value as "string" with it's constructor.
     */
    StringCreator();
    /**
     * @brief Creates a JsonString.
     *
     * @param value
     * @return Json*
     */
    Json *createJson(const string &value) const override;
    /**
     * @brief Get the value object.
     *
     * @param object
     * @return true if the passed value is surrounded by quotes, false otherwise.
     */
    bool getValue(const string &object) const override;
    /**
     * @brief Destroy the String Creator object.
     * Default destructor.
     */
    ~StringCreator() = default;
};

#endif