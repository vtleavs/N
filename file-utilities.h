#ifndef _FILE_UTILITES_H_
#define _FILE_UTILITES_H_

#include <string>
#include <vector>
#include "Word.h"
#include <stdio.h>

std::vector<std::vector<Word>> readSentencesFromFile(std::string filename);

void initFile(std::string filename);

bool validInFile(std::string filename);
bool validOutFile(std::string filename);


#endif
