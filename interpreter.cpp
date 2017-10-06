#ifndef _INTERPRETER_CPP_
#define _INTERPRETER_CPP_

#include "interpreter.h"

std::string interpret(std::vector<Word> phrase)
{
    for(int i = 0; i < phrase.size(); ++i)
    {
        if(phrase[i].getString() == "write" || phrase[i].getString() == "say")
        {
            return write(phrase, i);
        }
    }
    return "";
}

std::string write(std::vector<Word> phrase, int indexOfKeyword)
{
    std::string result;
    if(startsWithQuote(phrase[indexOfKeyword+1].getString()) && startsWithQuote(phrase[indexOfKeyword+1].getString()))
    {
        result = "std::cout << " + phrase[indexOfKeyword + 1].getString() + " << std::endl;";
    }
    else if(typeid(phrase[indexOfKeyword + 1].getString()).name() == "int")
    {

    }
    return result;
}

#endif
