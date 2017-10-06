#ifndef _PARSE_CPP_
#define _PARSE_CPP_

#include "parse.h"

void Phrase::convert()
{
    stringstream stream(phString);
    string word = "";
    bool inString = false;
    while(!stream.eof())
    {
        if(!inString && stream.peek() == '"')
            inString = true;
        if(inString && stream.peek() == '"')
            inString = false;
        if(!inString && stream.peek() == ' ')
        {
            char garb = stream.get();
            Word word_(word);
            words.push_back(word_);
            word = "";
        }
        word += stream.get();
    }
}

#endif
