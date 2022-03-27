// 关键字检索系统
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int BufferSize = 1e4 + 5; // 缓冲区大小

class FileToSol
{
private:
    ofstream fout;
    ifstream fin;
    string fileName, text; // 文件名、文本内容

public:
    FileToSol();
    ~FileToSol();

    // 显示源文件
    void printSource();

    // 获取KMP算法中的next数组
    void getNext(string subString, int *next);

    // KMP模式匹配算法
    int KMP(string main, string sub);

    // 关键字的查找
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
    text.clear(); // 清空当前文本内容之后开始写入
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
    char *buffer; // 缓冲区
    fin = ifstream(fileName.c_str());
    cout << endl
         << "显示源文件“" << fileName << "”：" << endl;
    while (!fin.eof())
    {
        buffer = new char[BufferSize];   // 缓冲区
        fin.getline(buffer, BufferSize); // 按行输入到buffer中
        cout << buffer << endl;          // 显示到终端
        delete[] buffer;                 // 清空buffer
    }
    cout << endl;
    fin.close();
}

void FileToSol::getNext(string subString, int *next)
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
            j = next[j]; // j值向前回溯，不断截短后缀向前匹配，直到匹配成功或者next(j)值为0
        }
    }
}

int FileToSol::KMP(string main, string sub)
{
    int ans = 0;               // 子串在主串中匹配到的次数
    unsigned int i = 0, j = 0; // 子串位置与主串位置

    // 获取next数组
    int *next = new int[sub.size() - 1];
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
            ans++;       // 匹配成功则次数+1
            j = next[j]; // j值继续回溯
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
    if (tmp.empty())
    {
        times += KMP(tmp, key);
    }
    return times;
}

int main()
{
    FileToSol testInstance;
    string keyWord;
    while (true)
    {
        cout << "请输入要检索的关键字：";
        cin >> keyWord;
        if (keyWord == "^")
        {
            cout << "系统退出！" << endl;
            break;
        }
        testInstance.printSource();
        cout << "在源文件中共检索到：" << testInstance.search(keyWord) << "个关键字：“" << keyWord << "”" << endl;
    }

    return 0;
}