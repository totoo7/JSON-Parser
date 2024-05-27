#include "JsonFactory.hpp"

string JsonCreator::removeDelimeters(const string& value, char openingDelimeter, char closingDelimeter) {
        size_t startPos = value.find(openingDelimeter);
        if (startPos == string::npos) return value;

        size_t endPos = value.find(closingDelimeter, startPos + 1);
        if (endPos == string::npos) return value;
        return value.substr(startPos + 1, endPos - startPos - 1);
}

JsonCreator::JsonCreator(const string &value) : value(value)
{
    JsonFactory::get().registerValidJson(this);
}