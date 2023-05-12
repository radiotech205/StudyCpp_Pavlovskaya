#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
    char punct[6] = {'.', ',', '?', '!', ':', ';'};
    set<char> punctuation(punct, punct + 6);

    ifstream in("../prose.txt");
    if(!in) {cout << "File is not found\n"; return 1;}

    map<string, int> wordCount;
    string s;
    while(in >> s)
    {
        int n = s.size();
        if(punctuation.count(s[n-1]))
            s.erase(n-1, n);

        ++wordCount[s];
    }

    ofstream out("freq_map.txt");
    map<string, int>::const_iterator it = wordCount.begin();
    for(it; it != wordCount.end(); it++)
    {
        out << setw(20) << left << it->first
            << setw(4) << right << it->second << endl;
    }
    cout << "Hello World!" << endl;
    return 0;
}
