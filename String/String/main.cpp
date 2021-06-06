#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class String
{
	int s;
	char* str;
public:
	char GetStr() { return *str; }
	String(int s = 255) { this->s = s; this->str = new char[s] {}; }
	String (const char* str)
	{
		this->s = strlen(str) + 1;
		this->str = new char[s];
		strcpy(this->str, str);
	}
	String(String& other)
	{
		this->s = other.s;
		this->str = new char[s] {};
		strcpy(this->str, other.str);
		cout << "CopyConstructor:\t" << this << endl;
	}
	void Print() { cout << this->str << endl; }
	String operator+(String& other)
	{
		int x = 0;
		s = strlen(this->str) + strlen(other.str) + 1;
		String str3(s);
		for (int i = 0; i < s; i++) {
			if (i < strlen(this->str)) str3.str[i] = this->str[i];
			else str3.str[i] = other.str[x++];
		}
		return str3;
	}
	String& operator=(String& other) 
	{ 
		this->s = other.s;
		this->str = new char[s] {};
		strcpy(this->str, other.str);
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	~String() { delete[] this->str; }
	friend ostream& operator<<(ostream& out, const String& other) { return out << other.str; }
	friend istream& operator>>(istream& in, String& other) { cout << "¬ведите строку: "; return  in >> other.str; }
};

int main()
{
	setlocale(LC_ALL, "ru");
	String str = "hello";
	String str2 = "world";
	cout << str + str2 << endl;
	str = str2;
	//cout << str << endl;
	String str4;
	cin >> str4;
	cout << str4 << endl;
	cout << str4 + str2 + str << endl;
	
	


	return 0;
}