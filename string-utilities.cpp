#ifndef _STRING_UTILITES_CPP_
#define _STRING_UTILTIES_CPP_

#include "string-utilities.h"

// std::vector<std::string> parseSentence(std::string & sentence) {
//     std::string * words = new std::string[100];
//     std::string::iterator itr = sentence.begin();
//     int wordCount = 0;
//     while((*itr) != '.' && itr != sentence.end()) {
//         std::string word;
//         if((*itr) == ' ') {
//             itr++;
//         }
//         while((*itr) != ' ' && (*itr) != '.' && itr != sentence.end()) {
//             word += (*itr);
//             itr++;
//         }
//         *(words+wordCount) = word;
//         wordCount++;
//     }
//     std::vector<std::string> words2;
//     for(int i = 0; i < wordCount; ++i) {
//         words2.push_back( *(words+i) );
//     }
//     if((*itr) == '.') {
//         return words2;
//     }
//     std::vector<std::string> failVector;
//     return failVector;
// }

std::vector<Word> parseSentenceToWords(std::string & sentence) {
    std::vector<Word> words;
    std::string::iterator itr = sentence.begin();
    int wordCount = 0;

    while((*itr) != '.' && itr != sentence.end()) {
        std::string word;
        if((*itr) == ' ') {
            itr++;
        }
        while((*itr) != ' ' && (*itr) != '.' && itr != sentence.end()) {
            word += (*itr);
            itr++;
        }
        Word word_(word);
        words.push_back(word_);
        wordCount++;
    }

    if((*itr) == '.') {
        return words;
    }
    std::vector<Word> failVector;
    return failVector;
}

bool endsInChar(std::string word, char c) {
    int length = strlen(word.c_str());
    if(word[length-1] == c) {
        return true;
    }
    return false;
}

std::vector<std::vector<Word>> parsePhraseToWords(std::vector<Word> sentence) {
    std::vector<std::vector<Word>> phrases;
    std::vector<Word> vc1;
    phrases.push_back(vc1);
    int i = 0;
    int phraseNum = 0;
    bool inQuote = false;
    while(i < sentence.size()) {
        if(startsWithQuote(sentence[i].getString()) && endsWithQuote(sentence[i].getString()))
        {
            inQuote = false;

            Word word_(sentence[i].getString());
            phrases[phraseNum].push_back(word_);
        }
        else if(startsWithQuote(sentence[i].getString()) && !inQuote)
        {
            inQuote = true;
            Word word_(sentence[i].getString() + " ");
            phrases[phraseNum].push_back(word_);
        }
        else if(endsWithQuote(sentence[i].getString()) && inQuote)
        {
            inQuote = false;
            Word word_(phrases[phraseNum][phrases[phraseNum].size()-1].getString() + sentence[i].getString());
            phrases[phraseNum][ phrases[phraseNum].size()-1 ] = word_;
        }
        else if(inQuote && endsInPunct(sentence[i].getString()) && endsWithQuote(stripPunct(sentence[i].getString())))
        {
            inQuote = false;
            Word word_(phrases[phraseNum][ phrases[phraseNum].size()-1 ].getString() + stripPunct(sentence[i].getString()));
            phrases[phraseNum][ phrases[phraseNum].size()-1 ] = word_;
            std::vector<Word> vc;
            phrases.push_back(vc);
            phraseNum++;
        }
        else if(inQuote && !endsInPunct(sentence[i].getString()) && !endsWithQuote(stripPunct(sentence[i].getString())))
        {
            Word word_(phrases[phraseNum][phrases[phraseNum].size()-1].getString() + sentence[i].getString() + " ");
            phrases[phraseNum][ phrases[phraseNum].size()-1 ] = word_;
        }
        else
        {
            Word word_(stripPunct(sentence[i].getString()));
            phrases[phraseNum].push_back(word_);
            if(endsInPunct(sentence[i].getString())) {
                std::vector<Word> vc;
                phrases.push_back(vc);
                phraseNum++;
            }
        }
        i++;
    }
    return phrases;
}

// std::vector<std::vector<std::string>> parsePhrase(std::vector<std::string> sentence) {
//     std::vector<std::vector<std::string>> phrases;
//     std::vector<std::string> vc1;
//     phrases.push_back(vc1);
//     int i = 0;
//     int phraseNum = 0;
//     bool inQuote = false;
//     while(i < sentence.size()) {
//         if(startsWithQuote(sentence[i]) && !inQuote)
//         {
//             inQuote = true;
//             phrases[phraseNum].push_back(sentence[i] + " ");
//
//             if(endsWithQuote(sentence[i]))
//                 inQuote = false;
//         }
//         else if(endsWithQuote(sentence[i]) && inQuote)
//         {
//             inQuote = false;
//             phrases[phraseNum][ phrases[phraseNum].size()-1 ] += sentence[i];
//         }
//         else if(inQuote && endsInPunct(sentence[i]) && endsWithQuote(stripPunct(sentence[i])))
//         {
//             inQuote = false;
//             phrases[phraseNum][ phrases[phraseNum].size()-1 ] += stripPunct(sentence[i]);
//             std::vector<std::string> vc;
//             phrases.push_back(vc);
//             phraseNum++;
//         }
//         else if(inQuote)
//         {
//             phrases[phraseNum][ phrases[phraseNum].size()-1 ] += sentence[i] + " ";
//         }
//         else
//         {
//             phrases[phraseNum].push_back(stripPunct(sentence[i]));
//             if(endsInPunct(sentence[i])) {
//                 std::vector<std::string> vc;
//                 phrases.push_back(vc);
//                 phraseNum++;
//             }
//         }
//         i++;
//     }
//     return phrases;
// }

void tagWords(std::vector<Word> & words)
{
    for(int i = 0; i < words.size(); ++i)
    {
        tagWord(words[i]);

        if(words[i].hasTag(WORD_SET))
        {
            if(!words[i+1].isKeyWord() && !words[i+1].isValue())
                words[i+1].addTag(WORD_VARNAME);
            else
                return;
        }
    }
}

void tagWord(Word & w)
{
    if(w.isKeyWord())
    {
        w.addTag(WORD_KEYWORD);
    }
    else if(w.isString())
    {
        w.addTag(WORD_VALUE);
        w.addTag(WORD_STRING);
    }
    else if(w.getString() == "if" || w.getString() == "If")
    {
        w.addTag(WORD_KEYWORD);
        w.addTag(WORD_IF);
    }
    // else if(w.isOperator())
    // {
    //     w.addTag(WORD_OPERATOR);
    // }
    else if(w.isNumber())
    {
        w.addTag(WORD_VALUE);
        w.addTag(WORD_NUMBER);
        if(w.isInt())
            w.addTag(WORD_INT);
        else if(w.isFloat())
            w.addTag(WORD_FLOAT);
    }
    //else if(!w.hasTag(WORD_KEYWORD))
    else
        w.addTag(WORD_USERDEF);

    if(isupper(w.getString()[0]) && w.hasTag(WORD_USERDEF))
    {
        w.addTag(WORD_CLASSNAME);
    }
    //std::cout << "[" << w.getTags().size() << "]";
}

bool endsInPunct(std::string word) {
    int length = strlen(word.c_str());
    if(word[length-1] == ',') {
        return true;
    }
    return false;
}

std::string stripPunct(std::string word) {
    if(endsInPunct(word)) {
        int length = strlen(word.c_str());
        return word.substr(0, length-1);
    }
    return word;
}

bool startsWithQuote(std::string word){
    if(word[0] == '"') {
        return true;
    }
    return false;
}

bool endsWithQuote(std::string word) {
    int length = strlen(word.c_str());
    if(word[length-1] == '"') {
        return true;
    }
    return false;
}


#endif
