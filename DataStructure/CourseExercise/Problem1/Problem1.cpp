#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

#include "StudentList.h"

void menuChoose(char& op)
{
	cout << "请选择您要进行的操作：";
	while (true)
	{
		op = _getch();
		if (op >= '0' && op <= '6'){
			cout << op << endl;
			break;
		}
		else{
			continue;
		}
	}
}

int main()
{
	int sNum, index;
	cout << "首先请建立考生信息系统!" << endl;
	cout << "请输入考生人数：";
	cin >> sNum;
	StudentList sList(sNum);
	Student* temp = sList.getFirstNode();
	sList.createListTail(sNum);
	cout << sList;
	cout << "操作列表：1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作，6为退出系统" << endl;
	char operation = 0;
	while (operation != -1)
	{
 		menuChoose(operation);
		switch (operation)
		{
			case '0':
				continue;
			case '1':
				cout << "请输入你要插入考生的位置：";
				cin >> index;
				sList.insertElem(index);
				break;
			case '2':
				cout << "请输入要删除考生的考号：";
				cin >> index;
				sList.deleteElem(sList.getElemByID(index));
				break;
			case '3':
				cout << "请输入要查找学生的考号：";
				cin >> index;
				*temp = sList.getElem(index);
				cout << "你所查找的学生信息为：" << endl << *temp << endl;
				break;
			case '4':
				cout << "请输入要修改学生的考号：";
				cin >> index;
				
				break;
			case '5':
				break;
			case '9':
				return 0;
		}
		cout << endl << sList;
	}
	return 0;
}