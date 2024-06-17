#ifndef JSON_PAIR_H
#define JSON_PAIR_H
#include "Json.hpp"
/**
 * @brief Object that holds JSON key-value pair.
 */
class JsonPair
{
public:
    /**
     * @brief Construct a new Json Pair object.
     */
    JsonPair();
    /**
     * @brief Construct a new Json Pair object with no key.
     * @param value 
     */
    JsonPair(const Json *value);
    /**
     * @brief Construct a new Json Pair object with passed JSON value and key.
     * @param value 
     * @param key 
     */
    JsonPair(const Json *value, const string &key);
    /**
     * @brief Construct a new Json Pair object.
     * Copy constructor.
     * @param other 
     */
    JsonPair(const JsonPair &other);
    /**
     * @brief Defines operator= 
     * @param other 
     * @return JsonPair&
     */
    JsonPair &operator=(const JsonPair &other);
    /**
     * @brief Prints the JsonPair object.
     */
    void print() const;
    /**
     * @brief Getter for value.
     * @return Json*
     */
    Json *getValue() const;
    /**
     * @brief Getter for key.
     * @return string 
     */
    string getKey() const;
    /**
     * @brief Setter for value.
     * @param value 
     */
    void setValue(const Json *value);
    /**
     * @brief Setter for key.
     * @param key
     */
    void setKey(const string &key);
    /**
     * @brief Destroy the Json Pair object.
     */
    ~JsonPair();

private:
    Json *value;
    string key;
};

#endif
