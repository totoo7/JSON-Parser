#ifndef OBJECT_CREATOR_H
#define OBJECT_CREATOR_H

#include "JsonCreator.hpp"
#include "JsonFactory.hpp"
#include "JsonObject.hpp"

class ObjectCreator : public JsonCreator
{
public:
    /**
     * @brief Construct a new ObjectCreator object.
     * Initializes the JsonCreator's value as "object" with it's constructor.
     */
    ObjectCreator();
    /**
     * @brief Creates a JsonObject.
     *
     * @param value
     * @return Json*
     */
    Json *createJson(const string &value) const override;
    /**
     * @brief Get the value object.
     *
     * @param object
     * @return true if passed value starts with '{', false otherwise.
     */
    bool getValue(const string &object) const override;
    /**
     * @brief Destroy the Object Creator object.
     * Default destructor.
     */
    ~ObjectCreator() = default;

private:
    /**
     * @brief Parses a key from a JSON object string.
     *
     * This method extracts the key from a JSON object string starting at the specified index.
     * The key is expected to be enclosed in double quotes. The method handles quoted keys and
     * updates the index to the position after the key-value separator (':').
     *
     * @param value The input string containing the JSON-like object.
     * @param index The current index in the input string, which will be updated to the position
     *              after the key-value separator (':') upon completion.
     * @return The parsed key as a string.
     */
    string parseObjectKey(const string &value, size_t &index) const;
    /**
     * @brief Parses a JSON object string and constructs a JsonObject.
     *
     * This method processes the input string to extract key-value pairs and constructs
     * a `JsonObject` from them. The extracted values are parsed
     * into `Json` objects using the `JsonFactory`. Each parsed key-value pair is stored
     * in a vector of `JsonPair` and used to create a new `JsonObject`.
     *
     * @param value The input string containing the JSON object to be parsed.
     * @return A pointer to the newly constructed `JsonObject`.
     */
    Json *parseObject(const string &value) const;
};

#endif