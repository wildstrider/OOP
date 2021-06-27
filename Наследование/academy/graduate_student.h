#pragma once
#include "Student.h"

class graduate_student :public Student
{
	string project;
public:
	const string& get_project() const;
	void set_project(const string& project);
	graduate_student(const string& last_name, const string& first_name, unsigned int age,
		             const string& speciality, const string& group, double rating, const string& project);
	void print() const;
	void Print(ostream& os) const;
	~graduate_student();
};
