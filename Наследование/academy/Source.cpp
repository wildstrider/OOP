#include <iostream>
#define delimiter "\n=====================================================\n"
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
	virtual void Print() const { cout << last_name << " " << first_name << " " << age << "лет." << endl; }
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		Set_last_name(last_name);
		Set_first_name(first_name);
		Set_age(age);
		cout << "Hconstructor: " << this << endl;
	}
	virtual ~Human() { cout << "Hdestructor: " << this << endl; }
	virtual void Print(ostream& os)	const { os << Get_last_name() << " " << Get_first_name() << " " << Get_age() << endl; }
	friend ostream& operator<<(ostream& os, const Human& obj); 
};


class Student :public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& Get_speciality() const { return speciality; }
	const string& Get_group() const { return group; }
	double Get_rating() const { return rating; }
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
	void Print(ostream& os) const
	{
		Human::Print();
		os << "специальность: " << Get_speciality() << " группа: " << Get_group() << " успеваемость: " << Get_rating() << endl;
	}
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
	 void Print(ostream& os) const
	{
		Human::Print();
		os <<  "специальность: " << Get_speciality() << " опыт преподавания: " << Get_expirience() << " лет." << endl;
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
	const string& get_project() const { return project; }
	void set_project(const string& project) { this->project = project; }
	graduate_student(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating, const string& project)
		: Student(last_name, first_name, age, speciality, group, rating) {
		set_project(project);
		cout << "g_sConstructor: " << this << endl;
	}
	void print() { Student::Print(); cout << " Название проекта: " << get_project() << endl; }
    void Print(ostream& os) { Student::Print(); os << " Название проекта: " << get_project() << endl; }
	~graduate_student() { cout << "g_sDestructor: " << this << endl; }
};

ostream& operator<<(ostream& os, const Human& obj) { obj.Print(os); return os; }
int main()
{
	setlocale(LC_ALL, "ru");
	//Human human("Тупенко", "Василий", 18);
	//human.Print();
	/*Student stud("Тупенко", "Василий", 18, "РПО", "BV-123", 43.4);
	stud.Print();
	Teacher Albert("Einstein", "Albert", 45, "Astrophisics", 120);
	Albert.Print();
	graduate_student gr_std("Тупенко", "Василий", 18, "РПО", "BV-123", 43.4, "морской бой");
	gr_std.print();*/
	Human* group[] =
	{
	 new Student("Васильев", "Александр", 23, "РПО", "ПВ-01", 90),
	 new graduate_student("Васильев", "Александр", 23, "РПО", "ПВ-01", 90, "морской бой"),
	 new Student("Васильева", "Маргарита", 25, "РПО", "ПВ-01", 90),
	 new Teacher("Ковтун", "Олег", 36, "Разработка приложение С++", 6),
	 new Student("Ивлев", "Александр", 29, "РПО", "ПВ-01", 95),
	 new Student("Рахманин", "Николай", 31, "РПО", "ПВ-01", 98),
	 new Teacher("Романов", "Андрей", 30, "HardwarePC", 10),
	 new Student("Нусс", "Дмитрий", 31, "РПО", "ПВ-01", 100),
	 new Student("Борн", "Евгений", 35, "РПО", "ПВ-01", 99)
	};

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		////group[i]->Print();
		//if(typeid(*group[i]) == typeid(Student))
		//{
		// cout << *dynamic_cast<Student*>(group[i]) << endl;
		//}
		//if (typeid(*group[i]) == typeid(Teacher))
		//{
		//	cout << *dynamic_cast<Teacher*>(group[i]) << endl;
		//}
		////cout << typeid(*group[i]).name() << endl;
		cout << *group[i];
		cout << delimiter << endl;
	}
	graduate_student D("Васильев", "Александр", 23, "РПО", "ПВ-01", 90, "морской бой");
	D.print();

	for (int i = 0; i < sizeof(group) / sizeof(Human*); delete group[i], i++);
	return 0;
}