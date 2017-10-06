
#include "includes.h"
#include "program.h"

int main(int argc, char const *argv[]) {
    if(argc != 2)
    {
        cout << "invalid filename\n\n";
        return 1;
    }
    if(!(argv[1][strlen(argv[1])-2] == '.'
        && argv[1][strlen(argv[1])-1] == 'n'))
    {
        cout << "invalid filename\n\n";
        return 1;
    }

    cout << "compiling " << argv[1] << "\n\n";

    Program program(argv[1]);
    program.parseFile();
    program.readOutPhrases();
    //program.compile();
    //program.output();


    return 0;
}
