#pragma once
#include <iostream>
#include <string>
using namespace std;

class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& Get_last_name()const;
	const string& Get_first_name()const;
	unsigned int Get_age() const;	
	void Set_last_name(const string& last_name);
	void Set_first_name(const string& first_name);
	void Set_age(unsigned int age);
	virtual void Print() const;
	Human(const string& last_name, const string& first_name, unsigned int age);
	virtual ~Human();
	virtual void Print(ostream& os) const;
};
ostream& operator<<(ostream& os, const Human& obj);
