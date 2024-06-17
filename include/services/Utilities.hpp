#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Namespace for functions various functions used in the project.
 */

namespace UTILITIES
{
    /**
     * @brief Splits a string into tokens based on a specified delimiter.
     *
     * This function splits the input string into a vector of substrings,
     * using the specified delimiter character to determine the boundaries of each token.
     *
     * @param value The input string to be split.
     * @param delimiter The character used to delimit the tokens.
     * @return A vector of strings containing the split tokens.
     */
    inline vector<string> split(const string &value, char delimeter)
    {
        vector<string> tokens;
        size_t start = 0, end = 0;
        while ((end = value.find(delimeter, start)) != string::npos)
        {
            tokens.push_back(value.substr(start, end - start));
            start = end + 1;
        }
        tokens.push_back(value.substr(start));
        return tokens;
    }

    /**
     * @brief Tokenizes a string into a vector of substrings, considering quoted substrings.
     *
     * This function splits the input string into tokens, treating quoted substrings as single tokens.
     * It handles both single and double quotes.
     *
     * @param input The input string to be tokenized.
     * @return A vector of strings containing the tokens.
     */
    inline vector<string> tokenize(const string &input)
    {
        vector<string> tokens;
        string token;
        bool inQuote = false;
        char quoteChar = '\0';

        for (size_t i = 0; i < input.size(); ++i)
        {
            char c = input[i];

            if (inQuote)
            {
                token += c; // Add the quote character
                if (c == quoteChar)
                {
                    inQuote = false;
                    tokens.push_back(token);
                    token.clear();
                }
            }
            else
            {
                if (c == '"' || c == '\'')
                {
                    if (!token.empty())
                    {
                        tokens.push_back(token);
                        token.clear();
                    }
                    inQuote = true;
                    quoteChar = c;
                    token += c; // Add the opening quote character
                }
                else if (isspace(c))
                {
                    if (!token.empty())
                    {
                        tokens.push_back(token);
                        token.clear();
                    }
                }
                else
                {
                    token += c;
                }
            }
        }

        if (!token.empty())
        {
            tokens.push_back(token);
        }

        return tokens;
    }

    /**
     * @brief Removes the specified opening and closing delimiters from a string.
     *
     * This function removes the first occurrence of the opening delimiter and the last
     * occurrence of the closing delimiter from the input string.
     *
     * @param value The input string from which delimiters will be removed.
     * @param openingDelimiter The character representing the opening delimiter.
     * @param closingDelimiter The character representing the closing delimiter.
     * @return A string with the delimiters removed.
     */
    inline string removeDelimeters(const string &value, char openingDelimeter, char closingDelimeter)
    {
        size_t startPos = value.find_first_of(openingDelimeter);
        size_t endPos = value.find_last_of(closingDelimeter);
        return value.substr(startPos + 1, endPos - startPos - 1);
    }

    /**
     * @brief Handles a quote character in a parsing context.
     *
     * This function manages the state changes when a quote character is encountered during parsing.
     * It updates the stack and the parsing flags, and adds the quote character to the new value string.
     *
     * @param current The current character being processed.
     * @param stack A stack used to keep track of delimiters.
     * @param inString A flag indicating if the parser is currently within a string.
     * @param inObject A flag indicating if the parser is currently within an object.
     * @param inList A flag indicating if the parser is currently within a list.
     * @param newValue The string being constructed during parsing.
     */
    inline void handleQuote(char current, vector<char> &stack, bool &inString, bool &inObject, bool &inList, string &newValue)
    {
        if (inObject || inList)
        {
            newValue += '\"';
            return;
        }

        char delimiter = '\"';

        if (stack.size() > 0)
        {
            if (stack.back() == delimiter)
            {
                inString = false;
                newValue += '\"';
                stack.pop_back();
            }
            else
            {
                inString = true;
                stack.push_back(delimiter);
            }
        }
        else
        {
            inString = true;
            newValue += '\"';
            stack.push_back(delimiter);
        }
    }

    /**
     * @brief Handles a space character in a parsing context.
     *
     * This function updates the index if the space character is at the end of the input string.
     *
     * @param current The current character being processed.
     * @param value The input string being parsed.
     * @param i The current index in the input string.
     * @param index The index to be updated if the space character is at the end.
     */
    inline void handleSpace(char current, const string &value, size_t i, size_t &index)
    {
        if (i == value.length() - 1)
            index = i + 1;
        return;
    }

    /**
     * @brief Handles a comma character in a parsing context.
     *
     * This function updates the index to the position after the comma character.
     *
     * @param current The current character being processed.
     * @param i The current index in the input string.
     * @param index The index to be updated to the position after the comma.
     */
    inline void handleComma(char current, size_t i, size_t &index)
    {
        index = i++;
        return;
    }

    /**
     * @brief Handles an open bracket character in a parsing context.
     *
     * This function updates the stack and parsing flags when an open bracket is encountered.
     *
     * @param current The current character being processed.
     * @param stack A stack used to keep track of delimiters.
     * @param newValue The string being constructed during parsing.
     * @param inList A flag indicating if the parser is currently within a list.
     */
    inline void handleOpenBracket(char current, vector<char> &stack, string &newValue, bool &inList)
    {
        char delimiter = '[';
        stack.push_back(delimiter);
        newValue += delimiter;
        inList = true;
    }

    /**
     * @brief Handles a close bracket character in a parsing context.
     *
     * This function updates the stack and parsing flags when a close bracket is encountered.
     *
     * @param current The current character being processed.
     * @param stack A stack used to keep track of delimiters.
     * @param newValue The string being constructed during parsing.
     * @param inList A flag indicating if the parser is currently within a list.
     */
    inline void handleCloseBracket(char current, vector<char> &stack, string &newValue, bool &inList)
    {
        char delimiter = ']';

        if (stack.back() == '[')
        {
            stack.pop_back();
            if (stack.back() != '[')
                inList = false;
        }

        newValue += delimiter;
    }

    /**
     * @brief Handles an open brace character in a parsing context.
     *
     * This function updates the stack and parsing flags when an open brace is encountered.
     *
     * @param current The current character being processed.
     * @param stack A stack used to keep track of delimiters.
     * @param newValue The string being constructed during parsing.
     * @param inObject A flag indicating if the parser is currently within an object.
     */
    inline void handleOpenBrace(char current, vector<char> &stack, string &newValue, bool &inObject)
    {
        char delimiter = '{';
        newValue += delimiter;
        stack.push_back(delimiter);
        inObject = true;
    }

    /**
     * @brief Handles a close brace character in a parsing context.
     *
     * This function updates the stack and parsing flags when a close brace is encountered.
     *
     * @param current The current character being processed.
     * @param stack A stack used to keep track of delimiters.
     * @param newValue The string being constructed during parsing.
     * @param inObject A flag indicating if the parser is currently within an object.
     */
    inline void handleCloseBrace(char current, vector<char> &stack, string &newValue, bool &inObject)
    {
        char delimiter = '}';

        if (stack.back() == '{')
        {
            stack.pop_back();
            if (stack.back() != '{')
                inObject = false;
        }

        newValue += delimiter;
    }

    /**
     * @brief Handles the case of missing delimiters in the stack.
     * 
     * This function prints an error message for each missing delimiter in the stack.
     * 
     * @param stack A stack used to keep track of delimiters.
     */
    inline void handleMissingDelimiters(const vector<char> &stack)
    {
        for (size_t i = 0; i < stack.size(); i++)
        {
            cout << "Incorrect format!" << endl;
            cout << "Missing delimiter(s):" << stack[i] << endl;
        }
    }

    /**
     * @brief Parses a value from a string, considering various delimiters.
     * 
     * This function parses a value from the input string, updating the index to the next position
     * after the parsed value. It handles nested structures and quotes, and checks for delimiter mismatches.
     * 
     * @param value The input string to be parsed.
     * @param index The current index in the input string, updated to the next position after the parsed value.
     * @return The parsed value as a string.
     */
    inline string parseValue(const string &value, size_t &index)
    {
        vector<char> stack;
        string newValue;
        bool inString = false, inObject = false, inList = false;

        for (size_t i = index; i < value.length(); i++)
        {
            char current = value[i];

            if (current == '\r' || current == '\n')
            {
                if (i == value.length() - 1)
                {
                    index = i + 1;
                    break;
                }
                continue;
            }

            if (current == '\"')
            {
                handleQuote(current, stack, inString, inObject, inList, newValue);
            }
            else if (current == ' ' && !inString && !inObject)
            {
                handleSpace(current, value, i, index);
            }
            else if (current == ',' && stack.empty())
            {
                handleComma(current, i, index);
                break;
            }
            else if (current == '[')
            {
                handleOpenBracket(current, stack, newValue, inList);
            }
            else if (current == ']')
            {
                handleCloseBracket(current, stack, newValue, inList);
            }
            else if (current == '{')
            {
                handleOpenBrace(current, stack, newValue, inObject);
            }
            else if (current == '}')
            {
                handleCloseBrace(current, stack, newValue, inObject);
            }
            else
            {
                newValue += value[i];
            }

            if (i == value.length() - 1)
                index = i + 1;
        }

        if (stack.empty())
        {
            return newValue;
        }
        else
        {
            handleMissingDelimiters(stack);
            index = string::npos;
            return "";
        }
    }

}

#endif