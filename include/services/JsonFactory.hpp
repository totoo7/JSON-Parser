#ifndef JSON_FACTORY_H
#define JSON_FACTORY_H

#include <fstream>
#include "JsonCreator.hpp"
using namespace std;

// Singleton
class JsonFactory
{
public:
    static JsonFactory &get();
    Json *parseValue(string value) const;
    Json *parseFile(string fileName) const;
    void registerValidJson(const JsonCreator *creator);
    const JsonCreator *getCreator(const string &value) const;
    JsonFactory(JsonFactory const &other) = delete;
    void operator=(JsonFactory const &other) = delete;
private:
    Json *parseValue(ifstream &ifs) const;
    vector<const JsonCreator*> creators;
    JsonFactory() {}
    ~JsonFactory() {}
};

#endif