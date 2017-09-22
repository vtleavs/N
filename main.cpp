#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <windows.h>

#include "string-utilities.h"
#include "file-utilities.h"
#include "Word.h"

int main(int argc, char const *argv[])
{
    //for(int i = 0; i < 1; ++i)
    //if(!validInFile(argv[1]))
    //{
        //std::cout << "No File Loaded:  Filename Invalid\n";
        initialzeFiles();

        Instruction ins("#include <string>");
        writeToIncludes(ins);

        std::cout << "Running Single Line Interpreter:\n\n";

        std::string sentence = "";
        getline(std::cin, sentence);

        std::vector<Word> words = parseSentenceToWords(sentence);

        if(words.size() == 0)
        {
            std::cout << "INVALID SENTENCE";
            return 1;
        }
        // for(std::string word : words)
        // {
        //     std::cout << word << std::endl;
        // }

        std::vector<std::vector<Word>> phrases = parsePhraseToWords(words);



        for(std::vector<Word> vec : phrases)
        {
            tagWords(vec);
            for(Word st : vec)
            {
                if(st.hasTag(WORD_KEYWORD))
                    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x0B );
                else if(st.hasTag(WORD_CLASSNAME))
                    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x02 );
                else if(st.hasTag(WORD_USERDEF))
                    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x03 );
                else if(st.hasTag(WORD_VALUE))
                    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x0C );

                std::cout << st.getString();
#if 0
                std::cout << " [";
                for(int t : st.getTags())
                {
                    std::cout << (int)t << ", ";
                }
                std::cout << "]";
#endif
                std::cout << " ";
                SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x0F );
            }
            std::cout << std::endl;
        }

    //}
    return 0;
}
