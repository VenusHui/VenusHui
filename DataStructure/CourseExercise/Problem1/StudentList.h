#pragma once
#ifndef STUDENTLIST_H_
#define STUDENTLIST_H_

#include "Student.h"

class StudentList
{
private:
	Student* firstNode;
	int listSize;
public:
	StudentList();
	// StudentList(const StudentList& theList);
	~StudentList();
	bool isEmpty() const { return listSize == 0; }
	int size() const { return listSize; }
	Student getElem(int index) const;
	void insertElem(int index, const Student& elem);
	void deleteElem(int index);
};
#endif // !STUDENTLIST_H_
