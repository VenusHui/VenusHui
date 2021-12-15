#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileToSol
{
private:
    ofstream fout;
    ifstream fin;
    string fileName, text;

public:
    FileToSol();
    ~FileToSol();
    void printSource();
    void getNext(string subString, int* next);
    int KMP(string main, string sub);
    int search(string s);
};

FileToSol::FileToSol()
{
    cout << "关键字检索系统" << endl;
    cout << "请输入文件名：";
    cin >> fileName;
    cin.clear();
    cin.ignore(65536, '\n');
    fout = ofstream(fileName.c_str());
    cout << "请输入一段英文：" << endl;
    char ch;
    text.clear();
    while (cin.get(ch) && ch != '^')
    {
        fout << ch;
        text.push_back(ch);
    }
    fout.close();
}

FileToSol::~FileToSol()
{
    fin.close();
    fout.close();
}

void FileToSol::printSource()
{
    char buffer[256];
    fin = ifstream(fileName.c_str());
    cout << endl
        << "显示源文件“" << fileName << "”：" << endl;
    while (!fin.eof())
    {
        fin.getline(buffer, 256);
        cout << buffer << endl;
    }
    cout << endl;
    fin.close();
}

void FileToSol::getNext(string subString, int* next)
{
    unsigned int i = 1, j = 0;
    next[1] = 0;
    while (i < subString.size())
    {
        if (j == 0 || subString.at(i - 1) == subString.at(j - 1))
        {
            next[++i] = ++j;
        }
        else
        {
            j = next[j];
        }
    }
}

int FileToSol::KMP(string main, string sub)
{
    int ans = 0;
    unsigned int i = 0, j = 0;
    int* next = new int[sub.size() - 1];
    getNext(sub, next);
    while (i < main.size())
    {
        if (main[i] == sub[j])
        {
            i++;
            j++;
        }
        if (j == sub.size())
        {
            ans++;
            j = next[j];
        }
        else if (i < main.size() && main.at(i) != sub.at(j))
        {
            if (j != 0)
            {
                j = next[j];
            }
            else
            {
                i++;
            }
        }
    }
    return ans;
}

int FileToSol::search(string key)
{
    int times = 0;
    string tmp;
    for (unsigned int i = 0; i < text.size(); i++)
    {
        if (text.at(i) != ' ')
        {
            tmp.push_back(text.at(i));
        }
        else
        {
            times += KMP(tmp, key);
            tmp.clear();
            continue;
        }
    }
    return times;
}

int main()
{
    FileToSol solution;
    string keyWord;
    bool loop = true;
    while (loop)
    {
        cout << "请输入要检索的关键字：";
        cin >> keyWord;
        if (keyWord == "^")
        {
            break;
        }
        solution.printSource();
        cout << "在源文件中共检索到：" << solution.search(keyWord) << "个关键字：“" << keyWord << "”" << endl;
    }

    return 0;
}