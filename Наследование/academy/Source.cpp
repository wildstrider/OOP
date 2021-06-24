#include <iostream>
using namespace std;

class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& Get_last_name() const { return last_name; }
	const string& Get_first_name() const { return first_name; }
	unsigned int Get_age() const { return age; }
	void Set_last_name(const string& last_name) { this->last_name = last_name; }
	void Set_first_name(const string& first_name) { this->first_name = first_name; }
	void Set_age(unsigned int age) { this->age = age; }
	void Print() { cout << last_name << " " << first_name << " " << age << "лет." << endl; }
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		Set_last_name(last_name);
		Set_first_name(first_name);
		Set_age(age);
		cout << "Hconstructor: " << this << endl;
	}
	~Human() { cout << "Hdestructor: " << this << endl; }
};

class Student :public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& Get_speciality() const { return speciality; }
	const string& Get_group() const { return group; }
	double Get_ratihg() const { return rating; }
	void Set_speciality(const string& speciality) { this->speciality = speciality; }
	void Set_group(const string& group) { this->group = group; }
	void Set_rating(double rating) { this->rating = rating; }
	void Print()
	{
		Human::Print();
		cout << "специальность: " << speciality << " группа: " << group << " успеваемость: " << rating << endl;
	}
	Student(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating
	) : Human(last_name, first_name, age)
	{
		Set_speciality(speciality);
		Set_group(group);
		Set_rating(rating);
		cout << "Sconstructor: " << this << endl;
	}
	~Student() { cout << "Sdestructor: " << this << endl; }
};

class Teacher :public Human
{
	string speciality;
	unsigned int expirience;
public:
	const string& Get_speciality() const { return speciality; }
	unsigned int Get_expirience() const { return expirience; }
	void Set_speciality(const string& speciality) { this->speciality = speciality; }
	void Set_expirence(unsigned int expirience) { this->expirience = expirience; }
	void Print()
	{
		Human::Print();
		cout << "специальность: " << speciality << " опыт преподавания: " << expirience << " лет." << endl;
	}
	Teacher(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int expirience) :Human(last_name, first_name, age)
	{
		this->speciality = speciality;
		this->expirience = expirience;
		cout << "Tconstructor: " << this << endl;
	}
	~Teacher() { cout << "Tdestructor: " << this << endl; }
};

class graduate_student :public Student
{
	string project;
public:
	const string get_project() const { return project; }
	void set_project(const string project) { this->project = project; }
	graduate_student(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating, const string& project)
		: Student(last_name, first_name, age, speciality, group, rating) { set_project(project); }
	void print() { Student::Print(); cout << " Название проекта: " << get_project() << endl; }
	~graduate_student() {}
};

int main()
{
	setlocale(LC_ALL, "ru");
	//Human human("Тупенко", "Василий", 18);
	//human.Print();
	Student stud("Тупенко", "Василий", 18, "РПО", "BV-123", 43.4);
	stud.Print();
	Teacher Albert("Einstein", "Albert", 45, "Astrophisics", 120);
	Albert.Print();
	graduate_student gr_std("Тупенко", "Василий", 18, "РПО", "BV-123", 43.4, "морской бой");
	gr_std.print();
	return 0;
}