#include "StudentList.h"

StudentList::StudentList()
{
	firstNode = new Student;
	listSize = 0;
}

StudentList::StudentList(int num)
{
	firstNode = new Student;
	listSize = num;
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
	while (firstNode != nullptr)
	{
		Student* nextNode = firstNode->getNext();
		delete firstNode;
		firstNode = nextNode;
	}
}

void StudentList::createListTail(int n)
{
	Student* pNode, * rNode;
	rNode = this->firstNode;
	cout << "请依次输入考生的考号、姓名、性别、年龄及报考类别！" << endl;
	for (int i = 0; i < n; i++)
	{
		pNode = new Student;
		cin >> *pNode;
		rNode->setNext(pNode);
		rNode = pNode;
	}
}

int StudentList::getElemByID(int admissionID) const
{
	int i = 1;
	Student* temp = firstNode->getNext();
	while (temp != nullptr || i > listSize)
	{
		if (temp->getID() == admissionID)
		{
			return i;
		}
		temp = temp->getNext();
		i++;
	}
	return -1;
}

Student& StudentList::getElem(int index) const
{
	Student* temp = firstNode;
	for (int i = 0; i < this->getElemByID(index); i++)
	{
		temp = temp->getNext();
	}
	return *temp;
}

void StudentList::insertElem(int index)
{
	Student* temp = new Student;
	Student* listDex = this->firstNode;
	cout << "请依次输入考生的考号、姓名、性别、年龄及报考类别！" << endl;
	cin >> *temp;
	int i = 1;
	while (this && i < index) {
		listDex = listDex->getNext();
		i++;
	}
	if (listDex == nullptr || i > listSize) {
		cout << "插入位置超出链表范围！" << endl;
		return;
	}
	temp->setNext(listDex->getNext());
	listDex->setNext(temp);
	this->listSize++;
	return;
}

void StudentList::deleteElem(int index)
{
	int i = 1;
	Student* temp = new Student;
	Student* listDex = this->firstNode;
	while (this && i < index) {
		listDex = listDex->getNext();
		i++;
	}
	if (listDex == nullptr || i > listSize) {
		cout << "插入位置超出链表范围！" << endl;
		return;
	}
	temp = listDex->getNext();
	listDex->setNext(temp->getNext());
	cout << "您删除的考生信息为：" << endl << *temp << endl;
	delete temp;
	listSize--;
}

ostream& operator<<(ostream& out, StudentList& list)
{
	const int gap = 8;
	out << setiosflags(ios::left) << setfill(' ') << setw(gap) << "考号" << setw(gap)
		<< "姓名" << setw(gap) << "性别" << setw(gap) << "年龄" << setw(gap) << "报考类别" << endl;
	Student* temp = list.firstNode->getNext();
	for (int i = 0; i < list.size(); i++)
	{
		out << setfill(' ') << setw(gap) << temp->getID() << setw(gap) << temp->getName();
		if (temp->getGender()) {
			out << setw(gap) << "男";
		}
		else {
			out << setw(gap) << "女";
		}
		out << setw(gap) << temp->getAge() << setw(gap) << temp->getCategory() << endl;
		temp = temp->getNext();
	}
	return out;
}
