#include "JsonFactory.h"

JsonCreator::JsonCreator(const string &value) : value(value)
{
    JsonFactory::get().registerValidJson(this);
}