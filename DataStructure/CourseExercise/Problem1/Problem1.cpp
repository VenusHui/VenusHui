#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

#include "StudentList.h"

void menuChoose(char& op)
{
	cout << "请选择您要进行的操作：";
	while (true) {
		op = _getch();
		if (op >= '0' && op <= '5') {
			cout << op << endl;
			break;
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
	ListNode<Student>* temp = new ListNode<Student>;
	cout << sList;
	cout << "操作列表：1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作" << endl;
	char operation = 0;
	while (operation != -1)
	{
		menuChoose(operation);
		switch (operation)
		{
			case '0':
				delete temp;
				return 0;
			case '1':
				cout << "请输入你要插入考生的位置：";
				cin >> index;
				sList.insertElem(index);
				break;
			case '2':
				if (!sList.size()) {
					cout << "信息表已为空，无法删除" << endl;
					break;
				}
				cout << "请输入要删除考生的考号：";
				cin >> index;
				sList.deleteElem(sList.getElemByID(index));
				break;
			case '3':
				if (!sList.size()) {
					cout << "信息表已为空，无法查找" << endl;
					break;
				}
				cout << "请输入要查找学生的考号：";
				cin >> index;
				*temp = sList.getElem(index);
				cout << "你所查找的学生信息为：" << endl << temp->data << endl;
				break;
			case '4':
				if (!sList.size()) {
					cout << "信息表已为空，无法修改" << endl;
					break;
				}
				cout << "请输入要修改学生的考号：";
				cin >> index;
				if (sList.getElemByID(temp->data.getID()) == -1) {
					cout << "考号为 " << index << " 的考生不存在，请核对后重新输入" << endl;
					break;
				}
				cout << "请依次输入修改后该学生的考号、姓名、性别、年龄及报考类别！" << endl;
				cin >> temp->data;
				if (sList.getElem(index).changeInfo(temp->data)) {
					cout << "修改成功" << endl;
				}
				else {
					cout << "修改失败" << endl;
				}
				break;
			case '5':
				sList.summary();
				break;
		}
		cout << endl << sList;
	}
	return 0;
}