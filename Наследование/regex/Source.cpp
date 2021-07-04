#include <iostream>
#include <string>
#include <regex>

using namespace std;
#define NAME_CHECK
int main()
{
	setlocale(LC_ALL, "ru");
	string last_name = "Tupenco";
	string first_name = "Vasya";
	//cout << "¬ведите фамилию, им€"; /*cin >> last_name >> first_name;*/
	regex rgx("[A-Z][a-z]{1,15}"); //regex - class, rgx- object
	if (regex_match(last_name, rgx/*, regex_constants::match_any*/))
	{
		cout << "Surname OK: " << last_name << endl;
	}
	else cout << "Bad surname!!!" << endl;
	if (regex_match(first_name, rgx))
	{
		cout << "name OK: " << first_name << endl;
	}
	else cout << "Bad name!!!" << endl;
	return 0;
}