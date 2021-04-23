#include<iostream>
#include<map>
#include <tuple>
#include <list>
#include<vector>

using namespace std;

struct Subject
{
	string subject;
	vector<int> marks;
	Subject(string subj, int mark)
	{
		subject = subj;
		marks.push_back(mark);
	}
	friend bool operator> (const Subject& s1, const Subject& s2);
	friend bool operator< (const Subject& s1, const Subject& s2);
};

struct Zachetka
{
	map<Subject, Teacher> m;
	void Add(string subj, int mark, Teacher teacher)
	{
		Subject s(subj, mark);
		m.emplace(s,teacher);
	}
};


class IUser
{
public:
	void virtual PrintAllMarks(string name) = 0;
};

class Teacher:public IUser
{
	
public:
	string name;
	Teacher(string name) 
	{
		this->name = name;
	}
	void PrintAllMarks(string n) override
	{
	}
	void SetMark(Student s,int m)
	{

	}
	void PrintStudListWithMarks(Subject)
	{

	}
	void PrintAllStudents()
	{

	}
};

class Admin:public IUser
{
	string name;
	list<Student> studList;
	list<Teacher> teacherList;
public:
	Admin(string name)
{
	this->name = name;
}
	void AddTeacher(Teacher t)
	{
		teacherList.push_back(t);
	}
	void AddStudent(Student s) {
		studList.push_back(s);
	}
	void PrintAllMarks(string n) override
	{
		for (auto iter = studList.begin(); iter->name == n && iter != studList.end(); iter++)
		{
		}
	}
	void PrintAllStudents()
	{

	}
	void PrintStudListWithMarks(Subject)
	{

	}
};

class Student :public IUser
{
public:
	Zachetka zachetka;
	string name;
	Student(string name)
	{
		this->name = name;
	}
	void PrintAllMarks(string n) override
	{
	
		for (auto it = zachetka.m.begin(); it != zachetka.m.end(); ++it)
		{
			cout << it->first.subject << " : " << it->second.name << endl;///вывод на экран
		}
	}
	friend bool operator> (const Student& s1, const Student& s2);
	friend bool operator< (const Student& s1, const Student& s2);
};
















int main()
{

	Admin a1("Иннокентий");
	Student s1("Акакий");
	Teacher t1("Рексар");





	return 0;
}

bool operator>(const Subject& s1, const Subject& s2)
{
	return s1.subject>s2.subject;
}

bool operator<(const Subject& s1, const Subject& s2)
{
	return s1.subject < s2.subject;
}

bool operator>(const Student& s1, const Student& s2)
{
	return s1.name > s2.name;
}

bool operator<(const Student& s1, const Student& s2)
{
	return s1.name < s2.name;
}



