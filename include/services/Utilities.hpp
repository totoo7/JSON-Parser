#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace UTILITIES
{
    
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

    inline string removeDelimeters(const string &value, char openingDelimeter, char closingDelimeter)
    {
        size_t startPos = value.find_first_of(openingDelimeter);
        size_t endPos = value.find_last_of(closingDelimeter);
        return value.substr(startPos + 1, endPos - startPos - 1);
    }

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

    inline void handleSpace(char current, const string &value, size_t i, size_t &index)
    {
        if (i == value.length() - 1)
            index = i + 1;
        return;
    }

    inline void handleComma(char current, size_t i, size_t &index)
    {
        index = i++;
        return;
    }

    inline void handleOpenBracket(char current, vector<char> &stack, string &newValue, bool &inList)
    {
        char delimiter = '[';
        stack.push_back(delimiter);
        newValue += delimiter;
        inList = true;
    }

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

    inline void handleOpenBrace(char current, vector<char> &stack, string &newValue, bool &inObject)
    {
        char delimiter = '{';
        newValue += delimiter;
        stack.push_back(delimiter);
        inObject = true;
    }

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

    inline void handleMissingDelimiters(const vector<char> &stack)
    {
        for (size_t i = 0; i < stack.size(); ++i)
        {
            cout << "Incorrect format!" << endl;
            cout << "Missing delimiter(s):" << stack[i] << endl;
        }
    }
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