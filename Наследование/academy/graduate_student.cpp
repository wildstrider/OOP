#include "graduate_student.h"

	const string& graduate_student::get_project() const { return project; }
	void graduate_student::set_project(const string& project) { this->project = project; }
	graduate_student::graduate_student(const string& last_name, const string& first_name, unsigned int age,
		                               const string& speciality, const string& group, double rating, const string& project)
		: Student(last_name, first_name, age, speciality, group, rating) 
	{
		set_project(project);
		cout << "g_sConstructor: " << this << endl;
	}
	void graduate_student::print() const { Student::Print(); cout << " Название проекта: " << get_project() << endl; }
	void graduate_student::Print(ostream& os) const { print(); }
	graduate_student::~graduate_student() { cout << "g_sDestructor: " << this << endl; }
