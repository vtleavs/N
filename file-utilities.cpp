#ifndef _FILE_UTILITES_CPP_
#define _FILE_UTILITES_CPP_

#include "file-utilities.h"

std::vector<std::vector<Word>> readSentencesFromFile(std::string filename)
{
    int length = filename.length();
    if(!validInFile(filename))
    {
        //throw an error
    }
}

void initFile(std::string filename)
{

}

bool validInFile(std::string filename)
{

    int length = filename.length();
    std::cout << filename[length-1] << std::endl;
    std::cout << filename[length-2] << std::endl;


    return filename[length-1] == 'n'
        && filename[length-2] == '.';
}

bool validOutFile(std::string filename)
{
    int length = filename.length();
    return filename[length-1] == 'e'
        && filename[length-2] == 'x'
        && filename[length-3] == 'e'
        && filename[length-4] == '.';
}

#endif
