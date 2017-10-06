#ifndef _PROGRAM_H_
#define _PROGRAM_H_

#include "includes.h"
#include "parse.h"

class Class{};
class Function{};
class Instruction{};
class Variable{};

class Int: public Variable{};
class Float: public Variable{};
class String: public Variable{};
class Bool: public Variable{};
class Char: public Variable{};

class Program
{
    public:
        Program(string filename_): filename(filename_) {}

        void parseFile();
        void compile();
        void output();
        void readOutPhrases();

    private:
        vector<string> fileToSentences();
        void sentenceToPhrases(string sent);

        vector<Phrase> progPhrases;

        vector<Class> classes;
        vector<Function> functions;
        vector<Instruction> includes;
        vector<Variable> globals;
        string filename;
};

#endif
