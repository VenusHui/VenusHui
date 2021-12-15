#include "Student.h"

Student::Student()
{
	_admissionID = 0;
	_gender = 0;
	_age = 0;
	_name = "";
	_category = "";
}

Student::Student(int id, int gender, int age, string name, string category)
{
	_admissionID = id;
	_gender = gender;
	_age = age;
	_name = name;
	_category = category;
}

Student::~Student()
{
}

bool Student::changeInfo(Student& newStudent)
{
	this->_admissionID = newStudent.getID();
	this->_name = newStudent.getName();
	this->_gender = newStudent.getGender();
	this->_age = newStudent.getAge();
	this->_category = newStudent.getCategory();
	return true;
}

istream& operator>> (istream& in, Student& s)
{
	string tmp;
	in >> s._admissionID >> s._name >> tmp >> s._age >> s._category;
	if (tmp == "男") {
		s._gender = Male;
	}
	else if (tmp == "女") {
		s._gender = Female;
	}
	else {
		cout << "性别输入不合法，请重新输入" << endl;
	}
	return in;
}

ostream& operator<<(ostream& out, Student& s)
{
	out << setiosflags(ios::left) << setfill(' ') << setw(gap) << "考号" << setw(gap)
		<< "姓名" << setw(gap) << "性别" << setw(gap) << "年龄" << setw(gap) << "报考类别" << endl;
	out << setfill(' ') << setw(gap) << s.getID() << setw(gap) << s.getName();
	if (s.getGender()) {
		out << setw(gap) << "男";
	}
	else {
		out << setw(gap) << "女";
	}
	out << setw(gap) << s.getAge() << setw(gap) << s.getCategory() << endl;
	return out;
}
