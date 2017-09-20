#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "string-utilities.h"
#include "Word.h"

int main(int argc, char const *argv[])
{
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
    tagWords(phrases[0]);

    for(std::vector<Word> vec : phrases)
    {
        for(Word st : vec)
        {
            std::cout << st.getString() << " [";
            for(char t : st.getTags())
            {
                std::cout << (int)t << ", ";
            }
            std::cout << "]; ";
        }
        std::cout << std::endl;
    }


    // std::cout << std::endl;
    // for(Word w : phrases[0])
    // {
    //     std::cout << w.getTags().size();
    //     for(char t : w.getTags())
    //     {
    //         std::cout << (int)t << ", ";
    //     }
    //     std::cout << std::endl;
    // }
    //std::cout << phrases[0][0];

    return 0;
}
