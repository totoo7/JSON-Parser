#include "JsonFactory.hpp"
#include "JsonValidator.hpp"

JsonFactory &JsonFactory::get()
{
    static JsonFactory instance;
    return instance;
}

void JsonFactory::registerValidJson(const JsonCreator *creator)
{
    creators.push_back(creator);
}

Json *JsonFactory::parseValue(const string &content) const
{
    const JsonCreator *crt = getCreator(content);
    if (!crt)
    {
        cerr << "Can't parse JSON data." << endl;
        return nullptr;
    }
    return crt->createJson(content);
}

Json *JsonFactory::parseValue(ifstream &ifs) const
{
    if (!ifs.is_open())
        return nullptr;

    string content;
    char character;
    while (ifs.get(character))
        content.push_back(character);

    ifs.close();
    JsonValidator validator(content);
    if (validator.validate()) {
        return parseValue(content);
    } else {
        cout << validator.getErrorMessage();
        return nullptr;
    }
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