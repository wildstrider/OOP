#include "Teacher.h"



	const string& Teacher::Get_speciality() const { return speciality; }
	unsigned int Teacher::Get_expirience() const { return expirience; }
	void Teacher::Set_speciality(const string& speciality) { this->speciality = speciality; }
	void Teacher::Set_expirence(unsigned int expirience) { this->expirience = expirience; }
	void Teacher::Print() const
	{
		Human::Print();
		cout << "специальность: " << Get_speciality() << " опыт преподавания: " << Get_expirience() << " лет." << endl;
	}
	void Teacher::Print(ostream& os) const { Print(); }
	Teacher::Teacher(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int expirience) :Human(last_name, first_name, age)
	{
		this->speciality = speciality;
		this->expirience = expirience;
		cout << "Tconstructor: " << this << endl;
	}
	Teacher::~Teacher() { cout << "Tdestructor: " << this << endl; }
