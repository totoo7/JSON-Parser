#ifndef JSON_ARRAY_H
#define JSON_ARRAY_H

#include "Json.hpp"

/**
 * @brief Class representing a JSON array.
 *
 * This class inherits from Json and manages an array of JSON objects.
 */
class JsonArray : public Json
{
public:
    /**
     * @brief Default constructor creating an empty JSON array.
     */
    JsonArray();
    /**
     * @brief Constructor initializing the JSON array with a vector of JSON pointers.
     *
     * @param value
     */
    JsonArray(const vector<Json*> &value);
    /**
     * @brief Copy constructor creating a deep copy of another `JsonArray` object.
     *
     * @param other
     */
    JsonArray(const JsonArray &other);
    /**
     * @brief Defines operator=, makes a deep copy of another `JsonArray` object.
     *
     * @param other
     * @return JsonArray&
     */
    JsonArray &operator=(const JsonArray &other);
    /**
     * @brief Clone method.
     *
     * @return Json*
     */
    Json *clone() const override;
    /**
     * @brief Logs the JSON array.
     *
     */
    void print() const override;
    /**
     * @brief Converts the JSON array to a string representation.
     *
     * @param indentLevel The indentation level for pretty-printing (default: 0).
     * @return String representation of the JSON array.
     */
    string toString(int indentLevel = 0) const override;
    /**
     * @brief Searches for a key within the JSON array.
     *
     * @param key The key to search for.
     * @return true if the key is found in any JSON object within the array, false otherwise.
     */
    const bool search(const string &key) const override;
    /**
     * @brief Checks if the JSON array contains a specific value.
     *
     * @param value The value to check for.
     * @return true if the value is found in any JSON object within the array, false otherwise.
     */
    const bool contains(const string &value) const override;
    /**
     * @brief Creates a JSON element within the array based on the provided path and value.
     * 
     * Add / after the array to create an element. Example:
     * create foo/ "bar" which would create an element "bar" in the array foo.
     *
     * @param path The path within the JSON structure where the modification should occur.
     * @param newValue The new JSON value to set at the specified path.
     * @param depth The current depth level within the JSON structure (internal use).
     */
    void create(const string &path, const string &newValue, int depth = 0) override;
    /**
     * @brief Erases a JSON object within the array based on the provided path.
     *
     * @param path The path within the JSON structure where the deletion should occur.
     * @param depth The current depth level within the JSON structure (internal use).
     */
    void erase(const std::string &path, int depth = 0) override;
    /**
     * @brief Destructor deallocating memory used by the JSON array.
     */
    ~JsonArray();
private:
    vector<Json *> values;
};

#endif
