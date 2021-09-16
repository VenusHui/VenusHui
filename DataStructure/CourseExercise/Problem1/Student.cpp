#include "Student.h"

Student::Student()
{
	_admissionID = 0;
	_gender = 0;
	_age = 0;
	_name = "";
	_category = "";
	_next = nullptr;
}

Student::Student(int id, int gender, int age, string name, string category, Student* next)
{
	_admissionID = id;
	_gender = gender;
	_age = age;
	_name = name;
	_category = category;
	_next = next;
}

Student::~Student()
{
}

istream& operator>> (istream& in, Student& s)
{
	in >> s._admissionID >> s._name >> s._gender >> s._age >> s._category;
	return in;
}

ostream& operator<<(ostream& out, Student& s)
{
	const int gap = 8;
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
