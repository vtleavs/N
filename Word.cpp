#ifndef _WORD_CPP_
#define _WORD_CPP_

#include "Word.h"

std::string Word::keywords[50] = {
    "write",
    "say",
    "is",
    "should",
    "be",
    "let",
    "set",
    "has",
    "a",
    // append 's
    "from",
    "in",
    "given",
    "run",
    "with",
    "on",
    "whether",
    "contains",
    "if",
    "else if",
    "otherwise",
    "set",
    "to",
    "retire",
    "delete",
    "remove",
    "of",
    "return",
    "and",
    "int",
    "ints",
    "where",
    "then"
};

bool Word::isValue()
{
    if(hasTag(WORD_VALUE))
        return true;
    if(isNumber() || isString() || isBool())
        return true;
    return false;
}

bool Word::isBool()
{
    if(hasTag(WORD_BOOL))
        return true;
    if(stringValue == "true" || stringValue == "false")
        return true;
    return false;
}

bool Word::isString()
{
    if(hasTag(WORD_STRING))
        return true;
    if(startsWithQuote() && endsWithQuote())
        return true;
    return false;
}

bool Word::isKeyWord()
{
    if(hasTag(WORD_KEYWORD))
        return true;
    for(std::string key : keywords)
    {
        if(stringValue == key)
        {
            return true;
        }
    }
    return false;
}

bool Word::isNumber()
{
    if(hasTag(WORD_NUMBER))
        return true;
    for(char c : stringValue)
    {
        if(c != '0' &&
            c != '1' &&
            c != '2' &&
            c != '3' &&
            c != '4' &&
            c != '5' &&
            c != '6' &&
            c != '7' &&
            c != '8' &&
            c != '9' &&
            c != '.' &&
            c != '-')
        {
            return false;
        }
    }
    return true;
}

bool Word::isInt()
{
    if(hasTag(WORD_INT))
        return true;
    if(!isNumber())
        return false;
    for(char c : stringValue)
    {
        if(c == '.')
            return false;
    }
    return true;
}

bool Word::isFloat()
{
    if(hasTag(WORD_FLOAT))
        return true;
    if(!isNumber())
        return false;
    for(char c : stringValue)
    {
        if(c == '.')
            return true;
    }
    return false;
}

bool Word::startsWithQuote()
{
    if(stringValue[0] == '"')
    {
        return true;
    }
    return false;
}

bool Word::endsWithQuote()
{
    int length = strlen(stringValue.c_str());
    if(stringValue[length-1] == '"')
    {
        return true;
    }
    return false;
}

bool Word::hasTag(int t)
{
    return find(tags.begin(), tags.end(), t) != tags.end();
}

#endif
