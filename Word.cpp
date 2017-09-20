#ifndef _WORD_CPP_
#define _WORD_CPP_

#include "Word.h"

std::string Word::keywords[31] = {
    "write",
    "say",
    "is",
    "should",
    "be",
    "let",
    "set",
    "has",
    "a",
    // prepend 's
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
    "ints"
};

bool Word::isNumber()
{
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
    if(!isNumber())
        return false;
    for(char c : stringValue)
    {
        if(c == '.')
            return true;
    }
    return false;
}

#endif
