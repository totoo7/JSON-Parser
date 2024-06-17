#ifndef NULL_CREATOR_H
#define NULL_CREATOR_H

#include "JsonCreator.hpp"
#include "JsonNull.hpp"

class NullCreator : public JsonCreator
{
public:
    /**
     * @brief Construct a new NullCreator object.
     * Initializes the JsonCreator's value as "null" with it's constructor.
     */
    NullCreator();
    /**
     * @brief Creates a JsonNull.
     *
     * @param value
     * @return Json*
     */
    Json *createJson(const string &value) const override;
    /**
     * @brief Get the value object.
     *
     * @param object
     * @return true if the passed value is a "null", false otherwise.
     */
    bool getValue(const string &object) const override;
    /**
     * @brief Destroy the NullCreator object.
     * Default desctructor.
     */
    ~NullCreator() = default;
};

#endif