#pragma once
#ifndef STUDENTLIST_H_
#define STUDENTLIST_H_

#include <iomanip>
#include "Student.h"

class StudentList
{
private:
	Student* firstNode;
	int listSize;
public:
	StudentList();
	StudentList(int num);
	StudentList(const StudentList& theList);
	~StudentList();
	void createListTail(StudentList* list, int n); // 使用尾插法进行单链表的整表创建
	bool isEmpty() const { return listSize == 0; } // 判断链表是否为空
	int size() const { return listSize; } // 获取链表长度
	Student* getFirstNode() const { return firstNode; }
	Student getElem(int index) const;
	void insertElem(int index, const Student& elem);
	void deleteElem(int index);
	friend ostream& operator<<(ostream& out, StudentList& list);
};
#endif // !STUDENTLIST_H_
