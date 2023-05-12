#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int l_name = 30;
const int l_year = 5;
const int l_pay = 10;
const int l_buf = l_name + l_year + l_pay;

class Man {
public:
    Man(int lName = 30);
    ~Man();
    bool CompareName(const char*) const;
    int GetBirthYear() const { return birth_year; }
    float GetPay() const { return pay; }
    char* GetName() const { return pName; }
    void Print() const;
    void SetBirthYear(const char*);
    void SetName(const char*);
    void SetPay(const char*);
private:
    char* pName;
    int birth_year;
    float pay;
    static int cnt;
};

int Man::cnt = 0;

Man::Man(int lName)
{
    this->pName = nullptr;
    this->birth_year = 0;
    this->pay = 0.0;

    cnt++;
    cout << "Constructor is working, cnt = "<< cnt << endl;
    this->pName = new char[lName + 1];
}
Man::~Man()
{
    cnt--;
    cout << "Destructor is working, cnt = "<< cnt << endl;
    delete [] pName;
}
void Man::SetName(const char* fromBuf)
{
    strncpy(this->pName, fromBuf, l_name);
    this->pName[l_name] = 0;
}
void Man::SetBirthYear(const char* fromBuf)
{
    this->birth_year = atoi(&fromBuf[l_name]);
    if(this->birth_year < 0)
        this->birth_year = 0;

}
void Man::SetPay(const char* fromBuf)
{
    this->pay = atof(&fromBuf[l_name + l_year]);
    if(this->pay < 0)
        this->pay = 0;
}
bool Man::CompareName(const char* name) const
{
    if ((strstr(this->pName, name)) && (this->pName[strlen(name)] == ' ' ) )
        return true;
    else
        return false;
}
void Man::Print() const
{
    cout << this->pName << this->birth_year << ' ' << this->pay << endl;
}
const char filename[] = "dbase.txt";

int main()
{
    const int maxn_record = 10;
    Man man[maxn_record];
    char buf [l_buf + 1];
    char name[l_name + 1];

    ifstream fin(filename);
    if(!fin)
    {
        cout << "Нет файла " << filename << endl;
        return 1;
    }
    int i = 0;
    while (fin.getline(buf, l_buf))
    {
        if ( i >= maxn_record)
        {
            cout << "Слишком длинный файл";
            return 1;
        }
        man[i].SetName(buf);
        man[i].SetBirthYear(buf);
        man[i].SetPay(buf);
        i++;
    }
    int n_record = i, n_man = 0;
    float mean_pay = 0;

    while (true)
    {
        cout << "Введите фамилию или слово end: ";
        cin >> name;
        if (0 == strcmp(name, "end")) break;
        bool not_found = true;
        for (i = 0; i < n_record; ++i)
        {
            if (man[i].CompareName(name))
            {
                man[i].Print();
                n_man++;
                mean_pay += man[i].GetPay();
                not_found = false;
                break;
            }
        }
        if(not_found)
            cout << "Такого сотрудника нет" << endl;
    }
    if(n_man)
        cout << " Средний оклад: " << mean_pay / n_man << endl;

    cout << "Hello World!" << endl;
    return 0;
}
