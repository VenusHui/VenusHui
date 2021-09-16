#include <iostream>
#include <string>
using namespace std;

#include "StudentList.h"

int main()
{
	int sNum;
	cout << "首先请建立考生信息系统!" << endl;
	cout << "请输入考生人数：" << endl;
	cin >> sNum;
	StudentList *sList;
	sList->createListTail(sList, sNum);
	cout << sList;
	cout << "操作列表：1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作，9为退出系统" << endl;
	char operation = 0;
	while (operation != -1)
	{
		cout << "请选择您要进行的操作：";
		cin >> operation;
		
		switch (operation)
		{
		case '0':
			continue;
		case '1':
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			break;
		case '9':
			return 0;
		}
	}
	return 0;
}