#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileToSol
{
private:
	ofstream fout;
	ifstream fin;
	string fileName, keyWord, text;
	int* next;
	
public:
	FileToSol();
	~FileToSol();
	void printSource();
	void getNext();
	void search();
};

FileToSol::FileToSol()
{
	cout << "关键字检索系统" << endl;
	cout << "请输入文件名：";
	cin >> fileName;
	fout = ofstream(fileName.c_str());
	fin = ifstream(fileName.c_str());
	cout << "请输入一段英文：" << endl;
	char ch;
	text.clear();
	while (cin.get(ch))
	{
		fout << ch;
		text.push_back(ch);
	}
	cin.clear();
	cin.ignore(65536, '\n');
}

FileToSol::~FileToSol()
{
	fin.close();
	fout.close();
}

void FileToSol::printSource()
{
	cout << endl << "显示源文件“" << fileName << "”：" << endl;
	char ch;
	while (fin.get(ch))
	{
		cout << ch;
	}
	fin.clear();
	fin.ignore(65536, '\n');
	cout << endl;
}

void FileToSol::getNext()
{
}

void FileToSol::search()
{
	cout << "请输入要检索的关键字：";
	cin >> keyWord;
}

int main()
{
	FileToSol solution;
	solution.search();
	return 0;
}