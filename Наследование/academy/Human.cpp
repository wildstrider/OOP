#include "Human.h"
#include <regex>

	const string& Human::Get_last_name() const { return last_name; }
	const string& Human::Get_first_name() const { return first_name; }
	unsigned int Human::Get_age() const { return age; }
	void Human::Set_last_name(const string& last_name)
	{
		regex en_rgx("[A-Z][a-z]{1,15}");
		regex ru_rgx("[А-Я][а-я]{1,15}");
		if (regex_match(last_name, en_rgx) || regex_match(last_name, ru_rgx)) this->last_name = last_name;
		else this->last_name = "Bad name";
	}
	void Human::Set_first_name(const string& first_name) 
	{
		regex en_rgx("([A-Z][a-z]{1,15}[ -]{0,1}){1,2}");
		//regex ru_rgx("[А-Я][а-я]{1,15}");
		regex ru_rgx("([А-Я][а-я]{1,15}[ -]{0,1}){1,2}");
		//regex ru_double_rgx("(ru_rgx)[ -](ru_rgx){0,1}");
		if (regex_match(first_name, en_rgx) || regex_match(first_name, ru_rgx)) this->first_name = first_name;
		else this->first_name = "Bad name";
	}
	void Human::Set_age(unsigned int age) 
	{
		if (age >= 18 && age <= 150) this->age = age;
		else this->age = 0;
	}
    void Human::Print() const { cout << Get_last_name() << " " << Get_first_name() << " " << Get_age() << "лет." << endl; }
	Human::Human(const string& last_name, const string& first_name, unsigned int age)
	{
		Set_last_name(last_name);
		Set_first_name(first_name);
		Set_age(age);
		cout << "Hconstructor: " << this << endl;
	}
    Human::~Human() { cout << "Hdestructor: " << this << endl; }
    void Human::Print(ostream& os) const { Print(); }

	ostream& operator<<(ostream& os, const Human& obj) { obj.Print(os); return os; }