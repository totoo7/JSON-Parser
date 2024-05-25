#include "NullCreator.hpp"

NullCreator::NullCreator() : JsonCreator("null") {}

Json *NullCreator::createJson(const string &value) const
{
    return new JsonNull();
}

bool NullCreator::getValue(const string &object) const
{
    return (object == "null");
}

static NullCreator creator;