#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Namespace for various functions used in the project.
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
                token += c;
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
                    token += c;
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
}

#endif