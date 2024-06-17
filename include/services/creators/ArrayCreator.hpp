#ifndef ARRAY_CREATOR_H
#define ARRAY_CREATOR_H

#include "JsonCreator.hpp"
#include "JsonFactory.hpp"
#include "JsonArray.hpp"

class ArrayCreator : public JsonCreator
{
public:
    /**
     * @brief Construct a new ArrayCreator object.
     * Initializes the JsonCreator's value as "array" with it's constructor.
     */
    ArrayCreator();
    /**
     * @brief Creates a JsonArray.
     *
     * @param value
     * @return Json*
     */
    Json *createJson(const string &value) const override;
    /**
     * @brief Get the value object.
     *
     * @param object
     * @return true if passed value starts with '[', false otherwise.
     */
    bool getValue(const string &object) const override;
    /**
     * @brief Destroy the Array Creator object.
     * Default desctructor.
     */
    ~ArrayCreator() = default;

private:
    /**
     * @brief Parses a JSON array string and constructs a JsonArray.
     *
     * This method processes the input string to extract values and constructs
     * a JsonArray from them. It uses UTILITIES::parseValue to extract values from
     * the input string. Each extracted value is parsed into a Json object using
     * the JsonFactory. The parsed Json objects are cloned and stored in a vector
     * of Json*, which is then used to create a new JsonArray. The temporary `Json`
     * objects are deleted after cloning to manage memory.
     *
     * @param value The input string containing the JSON array to be parsed.
     * @return A pointer to the newly constructed JsonArray.
     */
    Json *parseArray(const string &value) const;
};

#endif