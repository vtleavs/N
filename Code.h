#ifndef _CODE_H_
#define _CODE_H_

#include <vector>
#include <string>
#include "string-utilities.h"

#include "interpreter.h"

// class Variable
// {
//     public:
//         Variable(std::string name_, int value): name(name_), valueInt(value) {}
//         Variable(std::string name_, char value): name(name_), valueChar(value) {}
//         Variable(std::string name_, bool value): name(name_), valueBool(value) {}
//         Variable(std::string name_, float value): name(name_), valueFloat(value) {}
//         Variable(std::string name_, std::string value): name(name_), valueString(value) {}
//
//         int getValue(int x){ return valueInt; }
//         bool getValue(bool x){ return valueBool; }
//         std::string getValue(std::string x){ return valueString; }
//         char getValue(char x){ return valueChar; }
//         float getValue(float x){ return valueFloat; }
//
//         std::string getName() { return name; }
//
//         std::string getType();
//
//     private:
//         std::string name;
//         std::string valueString;
//         float valueFloat;
//         int valueInt;
//         char valueChar;
//         bool valueBool;
// };

class Instruction
{
    public:
        Instruction(std::vector<Word> instPhrase): instructionPhrase(instPhrase) {}

        //std::string getString() { return instructionString; }

        void compile();
        std::string getCompiled() { return compiledString; }

    private:
        std::vector<Word> instructionPhrase;
        std::string compiledString;
};

class Variable
{
    protected:
        std::string name;
    public:
        Variable(std::string name_): name(name_) {}

        virtual std::string getType() { return "none"; }
        std::string getName() { return name; }
        Instruction getAssignment() {
            Instruction ins();
            return ins;
        }
};

class Int: public Variable
{
    public:
        Int(std::string name_, int value_): value(value_), Variable(name_) {}

        std::string getType() { return "int"; }
    private:
        int value;
};

class Function
{
    public:
        Function(std::string name,
            std::string returnType,
            std::vector<Variable> args): functionName(name), functionType(returnType), arguments(args)
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
        std::vector<Variable> arguments;
        std::string compiledString;
        std::string functionType;
        std::string functionName;
};

class Class
{
    public:
        Class(std::string name): className(name) {}

        void compile();
        std::string getCompiled() { return compiledString; }

        void addMethod(Function f) { methods.push_back(f); }
        void addMember(Variable v) { members.push_back(v); }

    private:
        std::vector<Variable> members;
        std::vector<Function> methods;
        std::string compiledString;
        std::string className;

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
