#ifndef _INTERPRETER_CPP_
#define _INTERPRETER_CPP_

#include "interpreter.h"

// void interpret(std::vector<std::string> & sentence)
// {
//     std::vector<std::vector<Word>> phrases = parsePhraseToWords(parseSentenceToWords(sentence));
//
//     for(int i = 0; i < phrases.size(); ++i)
//     {
//         for(j = 0; j < phrases[i].size(); ++j)
//         {
//             if(phrases[i][j] == "write" || phrases[i][j] == "say")
//             {
//                 write(phrases[i], j);
//             }
//         }
//     }
// }

// void write(std::vector<std::string> phrase, int indexOfKeyword)
// {
//     std::string result;
//     if(startsWithQuote(indexOfKeyword+1) && startsWithQuote(indexOfKeyword+1))
//     {
//         result = "std::cout << " + phrase[indexOfKeyword + 1] + " << std::endl;";
//     }
//     else if(typeof(phrase[indexOfKeyword + 1]) == "int")
//     {
//
//     }
// }

#endif
