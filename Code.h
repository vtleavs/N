#ifndef _CODE_H_
#define _CODE_H_

#include <vector>
#include <string>

class Variable
{
    public:
        Variable(std::string name, int value){}
        Variable(std::string name, char value){}
        Variable(std::string name, bool value){}
        Variable(std::string name, std::string value){}
    private:

};

class Instruction
{
    public:
        Instruction(std::string instString): instructionString(instString) {}

        std::string getString() { return instructionString; }
    private:
        std::string instructionString;
};

class Function
{
    public:
        Function(std::vector<Variable> arguments){
            localVariables.insert( localVariables.end(),
                arguments.begin(),
                arguments.end() );
        }
    private:
        std::vector<Instruction> includes;
        std::vector<Variable> localVariables;
};

class Class
{
    public:
        Class(){}
    private:
        std::vector<Variable> members;
        std::vector<Function> methods;

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
