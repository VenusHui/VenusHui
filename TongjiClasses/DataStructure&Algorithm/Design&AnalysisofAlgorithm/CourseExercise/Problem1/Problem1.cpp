// 考试报名系统
/*                          Student.h                         */
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

const int gap = 8;
enum Gender { Female, Male };

class Student {
private:
  int _admissionID; // 准考证号
  int _gender;      // 性别
  int _age;         // 年龄
  string _name;     // 姓名
  string _category; // 报考类别

public:
  // 构造和析构函数
  Student();
  ~Student();

  // 设置和获取准考证号
  int getID() { return _admissionID; }
  void setID(int id) { _admissionID = id; }

  // 设置和获取性别
  int getGender() { return _gender; }
  void setGender(int gender) { _gender = gender; }

  // 设置和获取考生
  int getAge() { return _age; }
  void setAge(int age) { _age = age; }

  string getName() { return _name; }
  void setName(string name) { _name = name; }

  string getCategory() { return _category; }
  void setCategory(string category) { _category = category; }

  bool changeInfo(Student &newStudent);

  friend istream &operator>>(istream &in, Student &s);
  friend ostream &operator<<(ostream &out, Student &s);
};

/*                          Student.cpp                         */
Student::Student() {
  _admissionID = 0;
  _gender = 0;
  _age = 0;
  _name = "";
  _category = "";
}

Student::~Student() {}

bool Student::changeInfo(Student &newStudent) {
  this->_admissionID = newStudent.getID();
  this->_name = newStudent.getName();
  this->_gender = newStudent.getGender();
  this->_category = newStudent.getCategory();

  return true;
}

istream &operator>>(istream &in, Student &s) {
  string tmp;
  in >> s._admissionID >> s._name >> tmp >> s._age >> s._category;
  if (tmp == "男") {
    s._gender = Male;
  } else if (tmp == "女") {
    s._gender = Female;
  } else {
    cout << "性别输入不合法，请重新输入" << endl;
  }
  return in;
}

ostream &operator<<(ostream &out, Student &s) {
  out << setiosflags(ios::left) << setfill(' ') << setw(gap) << "考号"
      << setw(gap) << "姓名" << setw(gap) << "性别" << setw(gap) << "年龄"
      << setw(gap) << "报考类别" << endl;
  out << setfill(' ') << setw(gap) << s.getID() << setw(gap) << s.getName();
  if (s.getGender()) {
    out << setw(gap) << "男";
  } else {
    out << setw(gap) << "女";
  }
  out << setw(gap) << s.getAge() << setw(gap) << s.getCategory() << endl;
  return out;
}

/*                          StudentList.h                         */
template <typename Type>
struct ListNode // 链表结点
{
  Type data;
  ListNode *next;
  ListNode() : next(nullptr) {};
  ListNode(Type data) : data(data), next(nullptr) {};
  ListNode(ListNode<Type> *node) : data(node->data), next(node->next) {};
};

struct CatePair {
  string category;
  int num;
  CatePair() : category(""), num(0) {}
  CatePair(string cate) : category(cate), num(1) {}
};

class StudentList {
private:
  int listSize;                  // 表长
  int maleNum;                   // 男生人数
  int femaleNum;                 // 女生人数
  ListNode<Student> *first;      // 考生链表的头结点
  ListNode<CatePair> *cateFirst; // 报考种类链表的头结点

public:
  StudentList(int num);
  ~StudentList();

  bool isEmpty() const { return listSize == 0; } // 判断链表是否为空
  int size() const { return listSize; }          // 获取链表长度

  ListNode<Student> *getFirstNode() const { return first; }
  int getElemByID(
      int admissionID) const; // 获取学号为admissionID的Student在List中的编号

  ListNode<Student> *getElem(int index); // 获取编号为index的Student
  void insertElem(int index);            // 在编号index的Student后插入
  void deleteElem(int index);            // 删除编号为index的Student
  void changeElem();                     // 更改考生信息
  void summary();

  friend ostream &operator<<(ostream &out, StudentList &list);
};

/*                          StudentList.cpp                         */
StudentList::StudentList(int num) {
  first = new ListNode<Student>;
  cateFirst = nullptr;
  listSize = num;
  maleNum = femaleNum = 0;
  if (num == 0) {
    return;
  }
  ListNode<CatePair> *cateNode = cateFirst;
  ListNode<Student> *pNode = nullptr, *rNode = this->first;
  cout << "请依次输入考生的考号、姓名、性别、年龄及报考类别！" << endl;
  for (int i = 0; i < num; i++) {
    pNode = new ListNode<Student>;
    cin >> pNode->data;
    // 处理性别
    if (pNode->data.getGender() == Male) {
      maleNum++;
    } else {
      femaleNum++;
    }
    // 处理报考类别
    while (cateNode != nullptr) {
      if (cateNode->data.category == pNode->data.getCategory()) {
        cateNode->data.num++;
        break;
      }
      cateNode = cateNode->next;
    }
    if (cateNode == nullptr) {
      cateNode = new ListNode<CatePair>(pNode->data.getCategory());
      cateNode->next = cateFirst;
      cateFirst = cateNode;
    }

    rNode->next = pNode;
    rNode = pNode;
  }
}

StudentList::~StudentList() {
  while (first != nullptr) {

    ListNode<Student> *nextNode = first->next;
    delete first;
    first = nextNode;
  }
}

int StudentList::getElemByID(int admissionID) const {
  int i = 1;
  ListNode<Student> *temp = first->next;
  while (temp != nullptr || i > listSize + 1) {
    if (temp->data.getID() == admissionID) {
      return i;
    }
    temp = temp->next;
    i++;
  }
  return -1;
}

ListNode<Student> *StudentList::getElem(int index) {
  ListNode<Student> *temp = first;
  for (int i = 0; i < this->getElemByID(index); i++) {
    temp = temp->next;
  }
  return temp;
}

void StudentList::insertElem(int index) {
  int i = 1;
  ListNode<Student> *listDex = this->first;
  // 插入位置合法性判断
  if (listDex == nullptr || index > listSize + 1) {
    cout << "选择的插入位置超出信息表范围！" << endl;
    return;
  }
  ListNode<Student> *temp = new ListNode<Student>;
  cout << "请依次输入考生的考号、姓名、性别、年龄及报考类别！" << endl;
  cin >> temp->data;

  // 考号重复
  if (this->getElemByID(temp->data.getID()) != -1) {
    cout << "考号为 " << temp->data.getID()
         << " 的考生已经存在，请核对后重新输入" << endl;
    return;
  }
  // 处理性别
  if (temp->data.getGender() == Male) {
    maleNum++;
  } else {
    femaleNum++;
  }
  // 处理报考类别
  ListNode<CatePair> *cateNode = cateFirst;
  while (cateNode != nullptr) {
    if (cateNode->data.category == temp->data.getCategory()) {
      cateNode->data.num++;
      break;
    }
    cateNode = cateNode->next;
  }
  if (cateNode == nullptr) {
    cateNode = new ListNode<CatePair>(temp->data.getCategory());
    cateNode->next = cateFirst;
    cateFirst = cateNode;
  }

  // 定位插入位置
  while (i < index) {
    listDex = listDex->next;
    i++;
  }
  // 进行插入
  temp->next = listDex->next;
  listDex->next = temp;
  this->listSize++;
  return;
}

void StudentList::deleteElem(int index) {
  if (this->getElemByID(index) == -1) {
    cout << "考号为 " << index << " 的考生不存在，请核对后重新输入" << endl;
    return;
  } else {
    ListNode<Student> *pre = getElem(index - 1);
    ListNode<Student> *tmp = pre->next;
    // 处理性别
    if (tmp->data.getGender() == Male) {
      maleNum--;
    } else {
      femaleNum--;
    }
    // 处理报考类别
    ListNode<CatePair> *cateNode = cateFirst;
    while (cateNode != nullptr) {
      if (cateNode->data.category == tmp->data.getCategory()) {
        cateNode->data.num--;
        break;
      }
      cateNode = cateNode->next;
    }
    pre->next = tmp->next;
    cout << "你删除的考生信息为：" << tmp->data << endl;
    delete tmp;
  }
  listSize--;
}

void StudentList::changeElem() {
  int index;
  Student newStudent;
  cout << "请输入要修改学生的考号：";
  cin >> index;
  if (getElemByID(index) == -1) {
    cout << "考号为 " << index << " 的考生不存在，请核对后重新输入" << endl;
    return;
  }
  cout << "请依次输入修改后该学生的考号、姓名、性别、年龄及报考类别！" << endl;
  cin >> newStudent;
  ListNode<Student> *temp = getElem(index);
  temp->data.changeInfo(newStudent);
  // 处理性别
  if (temp->data.getGender() != newStudent.getGender()) {
    if (temp->data.getGender() == Male) {
      maleNum--, femaleNum++;
    } else {
      maleNum++, femaleNum--;
    }
  }
  // 处理报考类别
  if (temp->data.getCategory() != newStudent.getCategory()) {
    ListNode<CatePair> *cateNode = cateFirst;
    while (cateNode != nullptr) {
      if (cateNode->data.category == temp->data.getCategory()) {
        cateNode->data.num--;
        break;
      }
      cateNode = cateNode->next;
    }
    cateNode = cateFirst;
    while (cateNode != nullptr) {
      if (cateNode->data.category == newStudent.getCategory()) {
        cateNode->data.num++;
        break;
      }
      cateNode = cateNode->next;
    }
    if (cateNode == nullptr) {
      cateNode = new ListNode<CatePair>(newStudent.getCategory());
      cateNode->next = cateFirst;
      cateFirst = cateNode;
    }
  }
}

void StudentList::summary() {
  cout << "共有 " << listSize << "名考生，信息汇总如下：" << endl;
  cout << "男生： " << maleNum << "人        "
       << "女生： " << femaleNum << "人" << endl;
  ListNode<CatePair> *cateNode = cateFirst;
  while (cateNode != nullptr) {
    if (cateNode->data.num <= 0) {
      cateNode = cateNode->next;
      continue;
    }
    cout << "报考 " << cateNode->data.category << " 的人共有 "
         << cateNode->data.num << " 人" << endl;
    cateNode = cateNode->next;
  }
}

ostream &operator<<(ostream &out, StudentList &list) {
  if (list.listSize == 0) {
    return out;
  }
  out << setiosflags(ios::left) << setfill(' ') << setw(gap) << "考号"
      << setw(gap) << "姓名" << setw(gap) << "性别" << setw(gap) << "年龄"
      << setw(gap) << "报考类别" << endl;
  ListNode<Student> *temp = list.first->next;
  for (int i = 0; i < list.listSize; i++) {
    out << setfill(' ') << setw(gap) << temp->data.getID() << setw(gap)
        << temp->data.getName();
    if (temp->data.getGender()) {
      out << setw(gap) << "男";
    } else {
      out << setw(gap) << "女";
    }
    out << setw(gap) << temp->data.getAge() << setw(gap)
        << temp->data.getCategory() << endl;
    temp = temp->next;
  }
  return out;
}

/*                          Problem1.cpp                         */
void menuChoose(char &op) {
  cout << "请选择您要进行的操作：";
  while (true) {
    cin >> op;
    if (op >= '0' && op <= '5') {
      break;
    }
    cout << "操作输入有误" << endl;
    cin.clear();
    cin.ignore(65536, '\n');
  }
}

int main() {
  int sNum, index;
  cout << "首先请建立考生信息系统!" << endl;
  cout << "请输入考生人数：";
  cin >> sNum;
  StudentList sList(sNum);
  ListNode<Student> *temp = new ListNode<Student>;
  cout << sList;
  cout << "操作列表：1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作"
       << endl;
  char operation = 0;
  while (operation != -1) {
    menuChoose(operation);
    switch (operation) {
    case '0':
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
      sList.deleteElem(index);
      break;
    case '3':
      if (!sList.size()) {
        cout << "信息表已为空，无法查找" << endl;
        break;
      }
      cout << "请输入要查找学生的考号：";
      cin >> index;
      temp = sList.getElem(index);
      cout << "你所查找的学生信息为：" << endl << temp->data << endl;
      break;
    case '4':
      if (!sList.size()) {
        cout << "信息表已为空，无法修改" << endl;
        break;
      }
      sList.changeElem();
      break;
    case '5':
      sList.summary();
      break;
    }
    cin.clear();
    cin.ignore(65536, '\n');
    cout << endl << sList;
  }
  return 0;
}