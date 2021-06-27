#pragma once
#include "Human.h"

class Teacher :public Human
{
	string speciality;
	unsigned int expirience;
public:
	const string& Get_speciality() const;
	unsigned int Get_expirience() const;
	void Set_speciality(const string& speciality);
	void Set_expirence(unsigned int expirience);
	void Print() const;
	void Print(ostream& os) const;
	Teacher(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int expirience);
	~Teacher();
};