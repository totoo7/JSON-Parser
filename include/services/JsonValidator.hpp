#ifndef JSON_VALIDATOR_HPP
#define JSON_VALIDATOR_HPP

#include <string>
#include <vector>
using namespace std;
/**
 * @brief Class responsible for checking if the Json file is in the correct format.
 *
 */
class JsonValidator
{
public:
    /**
     * @brief Constructor for the JsonValidator class.
     *
     * Initializes a new instance of the JsonValidator class with the provided JSON string.
     *
     * @param json The JSON string to validate.
     */
    JsonValidator(const string &json);
    /**
     * @brief Validates the JSON string.
     *
     * This function starts the validation process by parsing the JSON string from the current position.
     * It returns true if the entire JSON string is valid, and false otherwise.
     *
     * @return true if the JSON string is valid, false otherwise.
     */
    bool validate();
    /**
     * @brief Returns the error message if the validation fails.
     *
     * This function returns a descriptive error message indicating the reason and the position
     * where the validation failed.
     *
     * @return A string containing the error message.
     */
    string getErrorMessage() const;

private:
    const string &json;
    size_t pos;
    string errorMessage;
    /**
     * @brief Skips any whitespace characters in the JSON string.
     *
     * Advances the position in the JSON string past any whitespace characters
     * (spaces, tabs, newlines, or carriage returns).
     */
    void skipWhitespace();
    /**
     * @brief Checks if a character is a whitespace character.
     *
     * @param c The character to check.
     * @return true if the character is a whitespace character, false otherwise.
     */
    bool isWhitespace(char c);
    /**
     * @brief Attempts to match and consume an expected character.
     *
     * If the character at the current position matches the expected character,
     * the position is advanced and the function returns true. Otherwise, it returns false.
     *
     * @param expected The expected character.
     * @return true if the expected character is found, false otherwise.
     */
    bool match(char expected);
    /**
     * @brief Parses a JSON value.
     *
     * This function attempts to parse a JSON value (e.g., string, object, array, number, literal).
     *
     * @return true if the value is successfully parsed, false otherwise.
     */
    bool parseValue();
    /**
     * @brief Parses a JSON object.
     *
     * This function attempts to parse a JSON object, which starts with '{' and ends with '}'.
     * The object contains key-value pairs, with the key being a string and the value being any JSON value.
     *
     * @return true if the object is successfully parsed, false otherwise.
     */
    bool parseObject();
    /**
     * @brief Parses a JSON array.
     *
     * This function attempts to parse a JSON array, which starts with '[' and ends with ']'.
     * The array contains a sequence of values separated by commas.
     *
     * @return true if the array is successfully parsed, false otherwise.
     */
    bool parseArray();
    /**
     * @brief Parses a JSON string.
     *
     * This function attempts to parse a JSON string, which is enclosed in double quotes.
     * It handles escape sequences and ensures the string is well-formed.
     *
     * @return true if the string is successfully parsed, false otherwise.
     */
    bool parseString();
    /**
     * @brief Parses an escape sequence in a JSON string.
     *
     * This function handles the escape sequences found in JSON strings, such as \", \\, \b, \f, \n, \r, \t, and \uXXXX.
     *
     * @return true if the escape sequence is valid, false otherwise.
     */
    bool parseEscapeCharacter();
    /**
     * @brief Parses a Unicode escape sequence in a JSON string.
     *
     * This function validates a Unicode escape sequence in the format \uXXXX,
     * where XXXX represents four hexadecimal digits.
     *
     * @return true if the Unicode escape sequence is valid, false otherwise.
     */
    bool parseUnicode();
    /**
     * @brief Checks if a character is a hexadecimal digit.
     *
     * @param c The character to check.
     * @return true if the character is a hexadecimal digit (0-9, a-f, A-F), false otherwise.
     */
    bool isHexDigit(char c);
    /**
     * @brief Checks if a character is a digit.
     *
     * @param c The character to check.
     * @return true if the character is a digit (0-9), false otherwise.
     */
    bool isDigit(char c);
    /**
     * @brief Parses a JSON number.
     *
     * This function attempts to parse a JSON number, which can include an optional
     * sign, integer part, fractional part, and exponent.
     *
     * @return true if the number is successfully parsed, false otherwise.
     */
    bool parseNumber();

    /**
     * @brief Parses a JSON literal (true, false, or null).
     *
     * This function attempts to parse JSON literals, which are the keywords true, false, and null.
     *
     * @return true if the literal is successfully parsed, false otherwise.
     */
    bool parseLiteral();
    /**
     * @brief Sets the error message.
     *
     * This function sets the error message when a validation error occurs,
     * including the specific message and the position in the JSON string where the error was detected.
     *
     * @param message The error message to set.
     */
    void setError(const string &message);
};

#endif