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

void initialzeFiles()
{
    std::ofstream includeFile;
    includeFile.open("GeneratedCodeFiles/includes.h", std::ios_base::out);
    includeFile << "#ifndef _INCLUDES_H_\n#define _INCLUDES_H_\n\n";
    includeFile << "#endif";
    includeFile.close();

    std::ofstream mainFile;
    mainFile.open("GeneratedCodeFiles/main.cpp");
    mainFile << "#include \"includes.h\"";
    mainFile.close();
}

void writeToIncludes(Instruction include)
{
    std::ofstream includeFile;
    includeFile.open("GeneratedCodeFiles/includes.h", std::ios_base::app);
    long pos = includeFile.tellp();
    includeFile.seekp(pos - 6);
    include.compile();
    includeFile << include.getCompiled() << "\n";
    includeFile.close();
}

#endif
