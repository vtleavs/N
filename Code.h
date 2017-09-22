#ifndef _CODE_H_
#define _CODE_H_

#include <vector>
#include <string>

#include "interpreter.h"

class Variable
{
    public:
        Variable(std::string name, int value): valueInt(value) {}
        Variable(std::string name, char value): valueChar(value) {}
        Variable(std::string name, bool value): valueBool(value) {}
        Variable(std::string name, float value): valueFloat(value) {}
        Variable(std::string name, std::string value): valueString(value) {}

        int getValue(int x){ return valueInt; }
        bool getValue(bool x){ return valueBool; }
        std::string getValue(std::string x){ return valueString; }
        char getValue(char x){ return valueChar; }
        float getValue(float x){ return valueFloat; }

    private:
        std::string valueString;
        float valueFloat;
        int valueInt;
        char valueChar;
        bool valueBool;
};

class Instruction
{
    public:
        Instruction(std::string instString): instructionString(instString) {}

        std::string getString() { return instructionString; }

        void compile();
        std::string getCompiled() { return compiledString; }
    private:
        std::string instructionString;
        std::string compiledString;
};

class Function
{
    public:
        Function(std::string name,
            std::string returnType,
            std::vector<Variable> arguments): functionName(name), functionType(returnType)
        {
            localVariables.insert( localVariables.end(),
                arguments.begin(),
                arguments.end() );
        }

        void compile();
        std::string getCompiled() { return compiledString; }

        void writeHeader(std::string className);
        void writeHeader();

        void addInstruction(Instruction ins) { instructions.push_back(ins); }

    private:
        std::vector<Instruction> instructions;
        std::vector<Variable> localVariables;
        std::string compiledString;
        std::string functionType;
        std::string functionName;
};

class Class
{
    public:
        Class(){}

        void compile();
        std::string getCompiled() { return compiledString; }

        void addMethod(Function f) { methods.push_back(f); }
        void addMember(Variable v) { members.push_back(v); }

    private:
        std::vector<Variable> members;
        std::vector<Function> methods;
        std::string compiledString;

};

class Code
{
    public:
        Code(){}

    private:
        std::vector<Class> classes;
        std::vector<Function> functions;
        std::vector<Variable> globalVariables;
        std::vector<Instruction> includes;
};


#endif
