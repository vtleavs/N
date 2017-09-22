#ifndef _CODE_CPP_
#define _CODE_CPP_

#include "Code.h"

void Instruction::compile()
{
    compiledString = interpret(instructionString);
}

void Function::compile()
{
    for(Instruction i : instructions)
    {
        i.compile();
        compiledString += i.getCompiled() + "\n";
    }
    compiledString += "}\n\n";
}

void Function::writeHeader(std::string className)
{
    compiledString += functionType + className "::" + functionName + "("
    for(for int i = 0; i < arguments.getSize()-1; ++i)
        compiledString += arguments[i].getType() + " " + arguments[i].getName() + ",";
    compiledString += arguments[arguments.getSize()].getType() + " "
        + arguments[arguments.getSize()].getName() + "){\n";
}

void Function::writeHeader()
{
    compiledString += functionType + functionName + "("
    for(for int i = 0; i < arguments.getSize()-1; ++i)
        compiledString += arguments[i].getType() + " " + arguments[i].getName() + ",";
    compiledString += arguments[arguments.getSize()].getType() + " "
        + arguments[arguments.getSize()].getName() + "){\n";
}

void Class::compile()
{
    compiledString += "class " + className + "{\n";
    compiledString += "public:\n";
    for(Function f : methods)
    {
        f.compile();
        f.writeHeader(className);
        compiledString += f.getCompiled() + "\n";
    }
    for(Variable v : members)
    {
        compiledString += v.getType() + " get" + v.getName() + "() "
            + "{ return " + v.getName() + "; }\n";
        compiledString += "void set" + v.getName() + "(" + v.getType() + "k) "
            + "{ " + v.getName() + "= k; }\n";
    }
    compiledString += "private:\n";
    for(Variable v : members)
    {
        compiledString += v.getType() + " " + v.getName() + ";\n";
    }
    compiledString += "};\n\n";
}

#endif
