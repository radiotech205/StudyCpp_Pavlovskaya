#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool equal(const string& cw, const string& w)
{
    char punct[] = {'.',',','?','!'};
    if(cw == w) return true;
    for(uint i = 0; i < sizeof(punct); i++)
        if(cw == (w + punct[i])) return true;
    return false;
}

int main()
{
    string word, curword;
    cout << "Введите слово для поиска:";
    cin >> word;

    ifstream fin("../infile.txt", ios::in);
    if(!fin) {cout << "Error of file`s opening" << endl; return 1;}

    int count = 0;
    while(!fin.eof())
    {
        fin >> curword;
        if(equal(curword, word))
            count++;
    }

    cout << "Количество вхождений слова: " << count << endl;

    cout << "Hello World!" << endl;
    return 0;
}
