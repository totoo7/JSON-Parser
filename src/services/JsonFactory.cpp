#include "JsonFactory.hpp"

JsonFactory &JsonFactory::get()
{
    static JsonFactory instance;
    return instance;
}

void JsonFactory::registerValidJson(const JsonCreator *creator)
{
    creators.push_back(creator);
}

Json *JsonFactory::parseValue(string content) const
{
    string value = content;
    const JsonCreator *crt = getCreator(value);
    if (!crt)
        throw runtime_error("Can't parse JSON.");
        
    return crt->createJson(value);
}

Json *JsonFactory::parseValue(ifstream &ifs) const
{
    if (!ifs.is_open())
        throw runtime_error("There was an error with the file.");

    string content;
    char character;
    while (ifs.get(character))
        content.push_back(character);

    ifs.close();
    return parseValue(content);
}

Json *JsonFactory::parseFile(string fileName) const
{
    ifstream ifs;
    ifs.open(fileName, ios::in);
    if (!ifs.is_open())
        throw invalid_argument("Can't find such file.");
    
    return parseValue(ifs);
}

const JsonCreator *JsonFactory::getCreator(const string &value) const
{
    for (size_t i = 0; i < creators.size(); i++)
    {
        if (creators[i]->getValue(value))
        {
            return creators[i];
        }
    }
    return nullptr;
}