#include "ObjectCreator.h"

string ObjectCreator::removeCurlyBraces(const string& value) const {
    size_t startPos = value.find("{");
    size_t endPos = value.find("}");
    string content;
    if (startPos != string::npos && endPos != string::npos) {
        content = value.substr(startPos + 1, endPos - startPos - 1);        
    }
    return content;
}