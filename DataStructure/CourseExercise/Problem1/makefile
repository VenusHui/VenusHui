Problem1: Problem1.o Student.o StudentList.o 
	g++ -std=c++17 -o Problem1 Problem1.o Student.o StudentList.o 
Problem1.o: Problem1.cpp StudentList.h 
	g++ -std=c++17 Problem1.cpp
StudentList.o: StudentList.cpp StudentList.h Student.o
	g++ -std=c++17 StudentList.cpp Student.o
Student.o: Student.cpp Student.h
	g++ -std=c++17 Student.cpp
clean: 
	rm Student.o StudentList.o Problem1.o
	