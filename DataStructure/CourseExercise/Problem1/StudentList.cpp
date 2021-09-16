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
	while (firstNode != 0)
	{
		Student *nextNode = firstNode->getNext();
		delete firstNode;
		firstNode = nextNode;
	}
}

void createListTail(StudentList *list, int n)
{
	Student *pNode, *rNode;
	list = new StudentList(n);
	rNode = list->getFirstNode();
	cout << "请依次输入考生的考号、姓名、性别、年龄及报考类别！" << endl;
	for (int i = 0; i < n; i++)
	{
		pNode = new Student;
		cin >> *pNode;
		rNode->setNext(pNode);
		rNode = pNode->getNext();
	}
}

Student StudentList::getElem(int index) const
{
	return Student();
}

void StudentList::insertElem(int index, const Student &elem)
{
}

void StudentList::deleteElem(int index)
{
}

ostream &operator<<(ostream &out, StudentList *list)
{
	const int gap = 8;
	out << setiosflags(ios::left) << setfill(' ') << setw(gap) << "考号" << setw(gap)
		<< "姓名" << setw(gap) << "性别" << setw(gap) << "年龄" << setw(gap) << "报考类别" << endl;
	Student *temp = list->getFirstNode();
	for (int i = 0; i < list->size(); i++)
	{
		out << setfill(' ') << setw(gap) << temp->getID() << setw(gap) << temp->getName();
		if (temp->getGender()){
			out << setw(gap) << "男";
		}
		else{
			out << setw(gap) << "女";
		}
		out << setw(gap) << temp->getAge() << setw(gap) << temp->getCategory() << endl;
	}
}