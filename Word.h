#ifndef _WORD_H_
#define _WORD_H_

#include <string>
#include <vector>
#include <cstring>
#include <iostream>

#define WORD_NONE 0
#define WORD_STRING 1
#define WORD_INT 2
#define WORD_FLOAT 3
#define WORD_KEYWORD 4
#define WORD_VARNAME 5
#define WORD_FUNCNAME 6
#define WORD_CLASSNAME 7
#define WORD_IF 8
#define WORD_SET 9
#define WORD_VALUE 10
#define WORD_NUMBER 11
#define WORD_OPERATOR 12

class Word
{
    public:
        Word(std::string string): Word(string, WORD_NONE) { }
        Word(std::string string, char tag):mainTag(tag), stringValue(string)
            { if(mainTag != WORD_NONE) tags.push_back(mainTag); }

        void setMainTag(char tag) { mainTag = tag; }
        char getMainTag() { return mainTag; }

        void addTag(char tag) { tags.push_back(tag); }
        std::vector<char> getTags() { return tags; }

        std::string getString() { return stringValue; }

        bool isNumber();
        bool isInt();
        bool isFloat();
        int getAsInt();
        float getAsFloat();

        static std::string keywords[31];

    private:
        std::string stringValue;
        char mainTag;
        std::vector<char> tags;

};

#endif
