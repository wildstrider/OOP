#include "Human.h"

	const string& Human::Get_last_name() const { return last_name; }
	const string& Human::Get_first_name() const { return first_name; }
	unsigned int Human::Get_age() const { return age; }
	void Human::Set_last_name(const string& last_name) { this->last_name = last_name; }
	void Human::Set_first_name(const string& first_name) { this->first_name = first_name; }
	void Human::Set_age(unsigned int age) { this->age = age; }
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