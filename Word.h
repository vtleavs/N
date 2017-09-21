#ifndef _WORD_H_
#define _WORD_H_

#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctype.h>

#define WORD_KEYWORD 11     // LEVEL 1 1 - -
#define WORD_OPERATOR 12    // LEVEL 1 2 - -
#define WORD_VALUE 13       // LEVEL 1 3 - -
#define WORD_USERDEF 14     // LEVEL 1 4 - -

#define WORD_NUMBER 231      // LEVEL 2 3 1 -

#define WORD_SET 3101          // LEVEL 3 1 0 1
#define WORD_IF 3102           // LEVEL 3 1 0 2

#define WORD_BOOL 3301        // LEVEL 3 3 0 1
#define WORD_STRING 3302       // LEVEL 3 3 0 2
#define WORD_INT 3311          // LEVEL 3 3 1 1
#define WORD_FLOAT 3312        // LEVEL 3 3 1 2

#define WORD_VARNAME 3401      // LEVEL 3 4 0 1
#define WORD_FUNCNAME 3402     // LEVEL 3 4 0 2
#define WORD_CLASSNAME 3403    // LEVEL 3 4 0 3

class Word
{
    public:
        Word(std::string string): stringValue(string) { }

        void addTag(int tag) { tags.push_back(tag); }
        std::vector<int> getTags() { return tags; }

        std::string getString() { return stringValue; }

        bool isKeyWord();
        bool isValue();
        bool isString();
        bool isBool();
        bool isNumber();
        bool isInt();
        bool isFloat();
        int getAsInt();
        float getAsFloat();

        bool startsWithQuote();
        bool endsWithQuote();

        bool hasTag(int t);

        static std::string keywords[50];

    private:
        std::string stringValue;
        std::vector<int> tags;

};

#endif
