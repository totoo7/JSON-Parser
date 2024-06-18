#ifndef JSON_H
#define JSON_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;
/**
 * @brief Base class for all JSON objects.
 */
class Json
{
public:
    /**
     * @brief Construct a new Json element.
     * Default constructor.
     */
    Json() = default;
    /**
     * @brief Construct a new Json element.
     * Default copy constructor.
     * @param rhs
     */
    Json(const Json &rhs) = default;
    /**
     * @brief Pure virtual method that logs the current JSON element in the terminal.
     * This method must be implemented by all derived classes for it's own JSON type.
     */
    virtual void print() const = 0;
    /**
     * @brief Pure virtual method that converts the value of the current JSON element to string.
     * This method must be implemented by all derived classes for it's own JSON type.
     * @param indentLevel
     * Optional parameter, used for formatting.
     * @return string
     */
    virtual string toString(int indentLevel = 0) const = 0;
    /**
     * @brief Pure virtual clone method.
     * This method must be implemented by all derived classes for it's own JSON type.
     * @return Json*
     */
    virtual Json *clone() const = 0;
    /**
     * @brief Searches for a given key within the JSON structure.
     *
     * @param key The key to search for in the JSON structure.
     * @return true If the key is found in the JSON structure.
     * @return false If the key is not found in the JSON structure.
     */
    virtual const bool search(const string &key) const;
    /**
     * @brief Pure virtual method that checks if a given value is contained within the JSON structure.
     * 
     * This method must be implemented by all derived classes that has this functionality.
     * 
     * @param value 
     * @return true 
     * @return false 
     */
    virtual const bool contains(const string &value) const = 0;
    /**
     * @brief Attempts to create a new JSON element located at the specified path. 
     * 
     * If the path is invalid the JSON state is not changed.
     * 
     * @param path Recursive path, separated by '/'. The last argument is the new key. 
     * @param newValue JSON value.
     * @param depth Optional parameter, not to be used.
     */
    virtual void create(const string &path, const string &newValue, int depth = 0) {}
    /**
     * @brief Replaces an existing JSON element's value with the newValue parameter.
     * 
     * If the path is invalid the JSON state is not changed.
     * 
     * @param path Recusive path, separated by '/'. The last argument is the existing JSON element.
     * @param newValue JSON value.
     * @param depth Optional parameter, not to be used.
     */
    virtual void set(const string &path, const string &newValue, int depth = 0) {}
    /**
     * @brief Deletes an existing JSON element located at the specified path.
     * 
     * If the path is invalid the JSON state is not changed.
     * 
     * @param path Recursive path, separated by '/'. The last argument is the existing JSON element's key that will be deleted.
     * @param depth Optional parameter, not to be used.
     */
    virtual void erase(const string &path, int depth = 0) {}
    /**
     * @brief Moves an existing JSON element from the first path to the second one.
     * 
     * If the path is invalid the JSON state is not changed.
     * 
     * The JSON element at the first path is deleted.
     * 
     * @param from Recursive path, separated by '/'. The last argument is the existing JSON element's key that will be moved.
     * @param to Recursive path, separated by '/'. The last argument is the JSON element's new location. 
     * Use './' when trying to move element at the top level of the JSON file.
     * @param depth Optional param, not to be used.
     */
    virtual void move(const string &from, string &to, int depth = 0) {}
    /**
     * @brief Destroy the Json object.
     * Default desctructor.
     */
    virtual ~Json() = default;
};

#endif
