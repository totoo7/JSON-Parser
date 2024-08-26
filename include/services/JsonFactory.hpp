#ifndef JSON_FACTORY_H
#define JSON_FACTORY_H

#include <fstream>
#include "JsonCreator.hpp"
using namespace std;

/**
 * @brief Polymorphic factory for JSON elements.
 * Uses the Factory auto-registration design pattern.
 * Uses Singleton pattern.
 */
class JsonFactory
{
public:
    /**
     * @brief This method ensures that there is only one instance of the class.
     * Provides global access to that instance.
     * 
     * @return JsonFactory& instance.
     */
    static JsonFactory &get();
    /**
     * @brief Attempts to parse the passed value and returns a new JSON element pointer, depending on the value.
     * 
     * @param value 
     * @return Json* 
     */
    Json *parseValue(const string &value) const;
    /**
     * @brief Attempts to parse the content of the passed file and returns a new JSON element pointer.
     * 
     * @param fileName 
     * @return Json* 
     */
    Json *parseFile(string fileName) const;
    /**
     * @brief Registers different JsonCreator objects. 
     * 
     * @param creator 
     */
    void registerValidJson(const JsonCreator *creator);
    /**
     * @brief Get the creator object depending on the passed value.
     * 
     * @param value 
     * @return const JsonCreator*.
     */
    const JsonCreator *getCreator(const string &value) const;
    /**
     * @brief Disallow construction of a new JsonFactory object.
     */
    JsonFactory(JsonFactory const &other) = delete;
    /**
     * @brief Disallow copying of the JsonFactory instance.
     */
    void operator=(JsonFactory const &other) = delete;
private:
    /**
     * @brief Reads the entire file into a string and calls the other parseValue method.
     * Closes the file after receiving it.
     * 
     * @param ifs 
     * @return Json* 
     */
    Json *parseValue(ifstream &ifs) const;
    vector<const JsonCreator *> creators;
    JsonFactory() {}
    ~JsonFactory() {}
};

#endif