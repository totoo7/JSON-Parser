#ifndef JSON_VALIDATOR_HPP
#define JSON_VALIDATOR_HPP

#include <string>
#include <vector>
using namespace std;

class JsonValidator {
public:
    JsonValidator(const string& json);
    bool validate();
    string getErrorMessage() const;
private:
    const string &json;
    size_t pos;
    string errorMessage;
    void skipWhitespace();
    bool isWhitespace(char c);
    bool match(char expected);
    bool parseValue();
    bool parseObject();
    bool parseArray();
    bool parseString();
    bool parseEscapeCharacter();
    bool parseUnicode();
    bool isHexDigit(char c);
    bool isDigit(char c);
    bool parseNumber();
    bool parseLiteral();
    void setError(const string &message);
};

#endif