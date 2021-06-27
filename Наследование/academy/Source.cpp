#include "Human.h"
#include "Student.h"
#include "Teacher.h"
#include "graduate_student.h"
#define delimiter "\n=====================================================\n"


int main()
{
	setlocale(LC_ALL, "ru");
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
		cout << *group[i];
		cout << delimiter << endl;
	}
	for (int i = 0; i < sizeof(group) / sizeof(Human*); delete group[i], i++);
	return 0;
}