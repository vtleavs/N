#ifndef _STRING_UTILITES_H_
#define _STRING_UTILTIES_H_

#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include "Word.h"
#include "interpreter.h"

//std::vector<std::string> parseSentence(std::string & sentence);
std::vector<Word> parseSentenceToWords(std::string & sentence);

void tagWords(std::vector<Word> & words);
void tagWord(Word & w);

bool inQuotes(std::string word);

bool startsWithQuote(std::string word);

bool endsWithQuote(std::string word);

//std::vector<std::vector<std::string>> parsePhrase(std::vector<std::string> sentence);
std::vector<std::vector<Word>> parsePhraseToWords(std::vector<Word> sentence);

bool endsInPunct(std::string word);

std::string stripPunct(std::string word);

bool isNumber(std::string word);

#endif
