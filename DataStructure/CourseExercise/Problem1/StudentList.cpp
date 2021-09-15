#include "StudentList.h"

StudentList::StudentList()
{
	firstNode = nullptr;
	listSize = 0;
}

//StudentList::StudentList(const StudentList& theList)
//{
//	listSize = theList.listSize;
//	if (listSize == 0)
//	{
//		firstNode == nullptr;
//		return;
//	}
//	else
//	{
//		Student* temp = theList.firstNode;
//		firstNode = new Student;
//		temp = temp->getNext();
//	}
//}

StudentList::~StudentList()
{
	while (firstNode != 0)
	{
		Student* nextNode = firstNode->getNext();
		delete firstNode;
		firstNode = nextNode;
	}
}

Student StudentList::getElem(int index) const
{
	return Student();
}

void StudentList::insertElem(int index, const Student& elem)
{
}

void StudentList::deleteElem(int index)
{
}
