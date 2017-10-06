#ifndef _PROGRAM_CPP_
#define _PROGRAM_CPP_

#include "program.h"

void Program::parseFile()
{
    vector<string> sentences = fileToSentences();
    for(string sentence : sentences){
        sentenceToPhrases(sentence);
        //cout << sentence << endl;
    }
}

void Program::readOutPhrases()
{
    for(Phrase p : progPhrases)
        cout << p.getString() << ", ";
}

vector<string> Program::fileToSentences()
{
    ifstream file;
    file.open(filename);

    bool inString = false;
    vector<string> sentences;
    string sentence = "";
    while(!file.eof())
    {
        if(!inString && file.peek() == '\n')
            char garb = file.get();
        if(!inString && file.peek() == '"')
            inString = true;
        if(inString && file.peek() == '"')
            inString = false;
        if(!inString && file.peek() == '.')
        {
            char garb = file.get();
            sentences.push_back(sentence);
            sentence = "";
        }
        sentence += file.get();
    }

    return sentences;
}

void Program::sentenceToPhrases(string sent)
{
    stringstream sentence(sent);
    bool inString = false;
    vector<Phrase> phrases;
    string phrase = "";
    while(!sentence.eof())
    {
        if(!inString && sentence.peek() == '"')
            inString = true;
        if(inString && sentence.peek() == '"')
            inString = false;
        if(!inString && sentence.peek() == ',')
        {
            char garb = sentence.get();
            Phrase phrase_(phrase);
            progPhrases.push_back(phrase_);
            phrase = "";
        }
        //if(!sentence.eof())
        phrase += sentence.get();
    }
    Phrase phrase_(phrase);
    progPhrases.push_back(phrase_);
    //progPhrases.phrases;
}

#endif
