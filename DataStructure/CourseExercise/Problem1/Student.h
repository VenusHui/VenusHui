#pragma once
#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
using std::string;

class Student
{
private:
    int _admissionID; // 准考证号
    int _gender;      // 性别
    int _age;         // 年龄
    string _name;     // 姓名
    string _category; // 报考类别
    Student* _next;

public:
    Student();
    Student(int id, int gender, int age, string name, string category, Student* next);
    ~Student();
    Student* getNext() { return _next; }
};
#endif // !_STUDENT_H_