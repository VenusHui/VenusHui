#include "StudentList.h"

StudentList::StudentList(int num)
{
	first = new ListNode<Student>;
	cateFirst = nullptr;
	listSize = num;
	maleNum = femaleNum = 0;
	if (num == 0) {
		return;
	}
	ListNode<CatePair>* cateNode = cateFirst;
	ListNode<Student>* pNode = nullptr, * rNode = this->first;
	cout << "请依次输入考生的考号、姓名、性别、年龄及报考类别！" << endl;
	for (int i = 0; i < num; i++)
	{
		pNode = new ListNode<Student>;
		cin >> pNode->data;
		// 处理性别
		if (pNode->data.getGender() == Male)
		{
			maleNum++;
		}
		else
		{
			femaleNum++;
		}
		// 处理报考类别
		while (cateNode != nullptr)
		{
			if (cateNode->data.category == pNode->data.getCategory())
			{
				cateNode->data.num++;
			}
			cateNode = cateNode->next;
		}
		cateNode = new ListNode<CatePair>(pNode->data.getCategory());
		cateNode->next = cateFirst;
		cateFirst = cateNode;

		rNode->next = pNode;
		rNode = pNode;
	}
}

StudentList::~StudentList()
{
	while (first != nullptr)
	{
		ListNode<Student>* nextNode = first->next;
		delete first;
		first = nextNode;
	}
}

int StudentList::getElemByID(int admissionID) const
{
	int i = 1;
	ListNode<Student>* temp = first->next;
	while (temp != nullptr || i > listSize + 1)
	{
		if (temp->data.getID() == admissionID)
		{
			return i;
		}
		temp = temp->next;
		i++;
	}
	return -1;
}

Student& StudentList::getElem(int index) const
{
	ListNode<Student>* temp = first;
	for (int i = 0; i < this->getElemByID(index); i++)
	{
		temp = temp->next;
	}
	return temp->data;
}

void StudentList::insertElem(int index)
{
	int i = 1;
	ListNode<Student>* listDex = this->first;
	if (listDex == nullptr || index > listSize + 1) {
		cout << "选择的插入位置超出信息表范围！" << endl;
		return;
	}
	ListNode<Student>* temp = new ListNode<Student>;
	cout << "请依次输入考生的考号、姓名、性别、年龄及报考类别！" << endl;
	cin >> temp->data;
	if (this->getElemByID(temp->data.getID()) != -1) {
		cout << "考号为 " << temp->data.getID() << " 的考生已经存在，请核对后重新输入" << endl;
		return;
	}
	// 处理性别
	if (temp->data.getGender() == Male)
	{
		maleNum++;
	}
	else
	{
		femaleNum++;
	}
	// 处理报考类别
	ListNode<CatePair>* cateNode = cateFirst;
	while (cateNode != nullptr)
	{
		if (cateNode->data.category == temp->data.getCategory())
		{
			cateNode->data.num++;
		}
		cateNode = cateNode->next;
	}
	cateNode = new ListNode<CatePair>(temp->data.getCategory());
	cateNode->next = cateFirst;
	cateFirst = cateNode;

	while (this && i < index) {
		listDex = listDex->next;
		i++;
	}
	temp->next = listDex->next;
	listDex->next = temp;
	this->listSize++;
	return;
}

void StudentList::deleteElem(int index)
{
	if (this->getElemByID(index) == -1) {
		cout << "考号为 " << index << " 的考生不存在，请核对后重新输入" << endl;
		return;
	}
	else
	{
		ListNode<Student> temp = getElem(index);

	}
	listSize--;
}

void StudentList::summary()
{
	cout << "共有 " << listSize << "名考生，信息汇总如下：" << endl;
	cout << "男生： " << maleNum << "人        " << "女生： " << femaleNum << "人" << endl;
	ListNode<CatePair>* cateNode = cateFirst;
	while (cateNode != nullptr)
	{
		cout << "报考 " << cateNode->data.category << " 的人共有 " << cateNode->data.num << " 人" << endl;
		cateNode = cateNode->next;
	}
}

ostream& operator<<(ostream& out, StudentList& list)
{
	if (list.listSize == 0)
	{
		return out;
	}
	out << setiosflags(ios::left) << setfill(' ') << setw(gap) << "考号" << setw(gap)
		<< "姓名" << setw(gap) << "性别" << setw(gap) << "年龄" << setw(gap) << "报考类别" << endl;
	ListNode<Student>* temp = list.first->next;
	for (int i = 0; i < list.listSize; i++)
	{
		out << setfill(' ') << setw(gap) << temp->data.getID() << setw(gap) << temp->data.getName();
		if (temp->data.getGender()) {
			out << setw(gap) << "男";
		}
		else {
			out << setw(gap) << "女";
		}
		out << setw(gap) << temp->data.getAge() << setw(gap) << temp->data.getCategory() << endl;
		temp = temp->next;
	}
	return out;
}
