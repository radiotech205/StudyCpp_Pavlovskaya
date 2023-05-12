#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

bool isLimit(char c)
{
    char lim[] = {' ', '\t', '\n'};
    for(uint i = 0; i < sizeof(lim); i++)
        if(c ==lim[i]) return true;

    return false;
}


int main()
{
    ifstream fin("../infile.txt", ios::in);
    if(!fin) {cout << "Error of file`s opening" << endl; return 1;}

    int count = 0;
    string word;
    ostringstream sentence;
    while(!fin.eof())
    {
        char symb;
        while(isLimit(symb = fin.peek()))
        {
            sentence << symb;
            if(symb == '\n') break;
            fin.seekg(1, ios::cur);
        }

        fin >> word;
        sentence << word;
        char last = word[word.size() - 1];
        if((last == '.') || (last == '!'))
        {
            sentence.str("");
            continue;
        }
        if(last == '?')
        {
            sentence.str("");
            count++;
        }
    }
    if(!count) cout << "Вопросительных предложений нет. \n";
    else    cout <<  "Вопросительных предложений: " << count << endl;

    cout << "Hello World!" << endl;
    return 0;
}
