#pragma once
#include "Human.h"

class Student :public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& Get_speciality() const;
	const string& Get_group() const;
	double Get_rating() const;
	void Set_speciality(const string& speciality);
	void Set_group(const string& group);
	void Set_rating(double rating);
	void Print() const;
	Student(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating); /*: Human(last_name, first_name, age)*/;
	~Student();
	void Print(ostream& os) const;
};

