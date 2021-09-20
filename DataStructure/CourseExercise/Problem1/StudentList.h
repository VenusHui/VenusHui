#pragma once
#ifndef STUDENTLIST_H_
#define STUDENTLIST_H_

#include <vector>
#include "Student.h"

typedef string* Res;

class StudentList
{
private:
	Student* firstNode;
	int listSize;
	int maleNum;
	int femaleNum;
	Res* cateRes;
public:
	StudentList();
	StudentList(int num);
	~StudentList();

	void createListTail(int n); // 使用尾插法进行单链表的整表创建
	bool isEmpty() const { return listSize == 0; } // 判断链表是否为空
	int size() const { return listSize; } // 获取链表长度

	Student* getFirstNode() const { return firstNode; }
	int getElemByID(int admissionID) const; // 获取学号为admissionID的Student在List中的编号

	Student& getElem(int index) const; // 获取编号为index的Student
	void insertElem(int index); // 在编号index的Student后插入
	void deleteElem(int index);	// 删除编号为index的Student
	void summary();

	friend ostream& operator<<(ostream& out, StudentList& list);
};
#endif // !STUDENTLIST_H_
