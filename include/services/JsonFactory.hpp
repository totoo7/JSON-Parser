#ifndef JSON_FACTORY_H
#define JSON_FACTORY_H

#include <iostream>
#include <string>
#include <fstream>
#include "JsonCreator.hpp"
using namespace std;

class Json;
// Singleton
class JsonFactory
{
public:
    static JsonFactory &get();
    Json *parseValue(string value) const;
    Json *parseFile(string fileName) const;
    void registerValidJson(const JsonCreator *rhs);
    const JsonCreator *getCreator(const string &_val) const;
    JsonFactory(JsonFactory const &rhs) = delete;
    void operator=(JsonFactory const &rhs) = delete;

private:
    Json *parseValue(ifstream &ifs) const;
    /*
    Creators:
        null
        bool
        int
        float
        string
        list
        object
    */
    const JsonCreator *creators[8];
    size_t count;
    JsonFactory() {}
    ~JsonFactory() {}
};

#endif