#include "Student.h"

	const string& Student::Get_speciality() const { return speciality; }
	const string& Student::Get_group() const { return group; }
	double Student::Get_rating() const { return rating; }
	void Student::Set_speciality(const string& speciality) { this->speciality = speciality; }
	void Student::Set_group(const string& group) { this->group = group; }
	void Student::Set_rating(double rating) { this->rating = rating; }
	void Student::Print() const
	{
		Human::Print();
		cout << "специальность: " << Get_speciality() << " группа: " << Get_group() << " успеваемость: " << Get_rating() << endl;
	}
	Student::Student(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating
	) : Human(last_name, first_name, age)
	{
		Set_speciality(speciality);
		Set_group(group);
		Set_rating(rating);
		cout << "Sconstructor: " << this << endl;
	}
	Student::~Student() { cout << "Sdestructor: " << this << endl; }
	void Student::Print(ostream& os) const { Print(); }

