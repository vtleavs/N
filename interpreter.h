#ifndef _INTERPRETER_H_
#define _INTERPRETER_H_

#include <typeinfo>
#include <string>
#include "string-utilities.h"
#include "Word.h"

// std::string keywords[31] = {
//     "write",
//     "say",
//     "is",
//     "should",
//     "be",
//     "let",
//     "set",
//     "has",
//     "a",
//     // prepend 's
//     "from",
//     "in",
//     "given",
//     "run",
//     "with",
//     "on",
//     "whether",
//     "contains",
//     "if",
//     "else if",
//     "otherwise",
//     "set",
//     "to",
//     "retire",
//     "delete",
//     "remove",
//     "of",
//     "return",
//     "and",
//     "int",
//     "ints"
// };

std::string interpret(std::vector<Word> phrase);
std::string write(std::vector<Word> phrase, int indexOfKeyword);

#endif
