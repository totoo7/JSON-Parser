#ifndef JSON_OBJECT_H
#define JSON_OBJECT_H

#include "Json.hpp"
#include "JsonPair.hpp"

/**
 * @brief Represents a JSON object consisting of key-value pairs.
 * This class inherits from Json.
 */
class JsonObject : public Json
{
public:
    /**
     * @brief Default constructor for JsonObject.
     */
    JsonObject();
    /**
     * @brief Constructor that initializes JsonObject with given pairs.
     * @param other
     */
    JsonObject(const vector<JsonPair> &other);
    /**
     * @brief Copy constructor for JsonObject.
     * @param other
     */
    JsonObject(const JsonObject &other);
    /**
     * @brief Defines operator=
     * @param other
     * @return JsonObject&
     */
    JsonObject &operator=(const JsonObject &other);
    /**
     * @brief Searches for the presence of a key in the JsonObject.
     * @param key
     * @return true if the key is found, false otherwise.
     */
    const bool search(const string &key) const;
    /**
     * @brief Creates a new element in the JsonObject at the specified path with the given value.
     * @param path The path where the new element should be created. The last argument is the new key.
     * @param newValue The JSON string representing the new value.
     * @param depth The current depth in the path traversal.
     */
    void create(const string &path, const string &newValue, int depth);
    /**
     * @brief Sets the value of an existing element in the JsonObject at the specified path.
     * @param path The path where the element exists. 
     * @param newValue The JSON string representing the new value.
     * @param depth The current depth in the path traversal.
     */
    void set(const string &path, const string &newValue, int depth);
    /**
     * @brief Erases an element from the JsonObject at the specified path.
     * @param path The path where the element should be erased. The last argument is the key that will be deleted.
     * @param depth The current depth in the path traversal.
     */
    void erase(const string &path, int depth);
    /**
     * @brief Moves an element from one path to another within the JsonObject.
     * @param from The original path of the element to move. The last argument is the key that will be moved.
     * @param to The destination path where the element should be moved.
     * @param depth The current depth in the path traversal.
     */
    void move(const string &from, string &to, int depth);
    /**
     * @brief Clone method.
     * @return JsonObject*
     */
    Json *clone() const;
    /**
     * @brief Logs the object.
     */
    void print() const;
    /**
     * @brief Checks if the JsonObject contains a specific value.
     * @param value The value to check for within the JsonObject.
     * @return true if the value is found in any nested JSON object or array, false otherwise.
     */
    const bool contains(const string &value) const;
    /**
     * @brief Converts the JsonObject to a JSON string representation.
     * @param indentLevel The indentation level for pretty-printing (default: 0).
     * @return A string representing the JSON object.
     */
    string toString(int indentLevel = 0) const;
    /**
     * @brief Destructor for JsonObject.
     */
    ~JsonObject();
private:
    vector<JsonPair> pairs;
};

#endif
