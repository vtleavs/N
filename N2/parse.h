#ifndef _PARSE_H_
#define _PARSE_H_

#include "includes.h"

class Word
{
    public:
        Word(string string): stringValue(string) { }

        void addTag(int tag) { tags.push_back(tag); }
        vector<int> getTags() { return tags; }

        string getString() { return stringValue; }

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

        static string keywords[50];

    private:
        string stringValue;
        vector<int> tags;

};

class Phrase
{
    public:
        Phrase(string ph): phString(ph) {}

        void convert();
        string getString() { return phString; }
        vector<Word> getWords();
        string getType();
    private:
        string type;
        string phString;
        vector<Word> words;
};

class ClassP: public Phrase {
};

class FunctionP: public Phrase {
};

class VariableP: public Phrase {
};

class ExecutableP: public Phrase {
};



#endif
