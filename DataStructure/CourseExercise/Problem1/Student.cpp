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
	in >> s._admissionID >> s._name >> s._age >> s._gender >> s._category;
}