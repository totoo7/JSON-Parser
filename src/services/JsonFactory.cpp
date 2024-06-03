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
    {
        cerr << "Couldn't parse Json." << endl;
        return nullptr;
    }
    return crt->createJson(value);
}

Json *JsonFactory::parseValue(ifstream &ifs) const
{
    if (!ifs.is_open())
    {
        cout << "Failed to open file\n";
        return nullptr;
    }

    string content;
    char character;
    while (ifs.get(character))
    {
        content.push_back(character);
    }

    ifs.close();
    return parseValue(content);
}

Json *JsonFactory::parseFile(string fileName) const
{
    ifstream ifs;
    ifs.open(fileName, ios::in);
    if (!ifs.is_open())
        return nullptr;

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