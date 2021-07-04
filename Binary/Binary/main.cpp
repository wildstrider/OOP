#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <bitset>
using namespace std;
class Binary;

//Binary operator+(Binary& left, Binary& right);

class Binary
{
	//int d;
	int size;
	char* bin;
public:
	char Gerbinary() const { return *this->bin; }
	int GetSize() const { return size; }
	Binary(const char* bin)
	{
		this->size = strlen(bin) + 1;
		this->bin = new char[size] {};
		strcpy(this->bin, bin);
	}
	int  bin_to_dec(char str[])
	{
		int sum = 0;
		int k = strlen(str);
		for (int i = 0; str[i]; i++) {

			if (str[i] != ' ') {
				sum += (str[i] - '0') * pow(2, --k);
			}
		}
		return sum;
	}
	Binary operator+(Binary& right)
	{
		int temp = 0;
		Binary C(7);
		int s = 3;
		for (int i = 3; i >= 0; i--) {
			
			if(this->bin[i] == '1' && right.bin[i] == '1') (temp)? C.bin[i] = '1', temp-- : C.bin[i] = '0', temp++;

			if (this->bin[i] == '0' && right.bin[i] == '1' || this->bin[i] == '1' && right.bin[i] == '0')
			{
				if (temp) 
				{
					C.bin[i] = '0'; 
					//temp--; 
			    }
				else C.bin[i] = '1'; 
				
			}
			if (this->bin[i] == '0' && right.bin[i] == '0')
			{
				if (temp) 
				{
					C.bin[i] = '1'; 
					temp--;
				}
				else C.bin[i] = '0';
			}
		}
		return C;
	}
	Binary operator-(Binary& right)
	{
		int x = this->bin_to_dec(bin);
		int y = right.bin_to_dec(bin);
		if (x < y) 
		{

			x = -this->bin_to_dec(bin);
			x = y - x;
		}
		else y = -right.bin_to_dec(bin);

	}
	Binary operator*(Binary& right)
	{
		int temp = 0;
		Binary C(7);
		int s = 3;
		for (int i = 3; i >= 0; i--) {

			

			//if (this->bin[i] == '0' && right.bin[i] == '1' || this->bin[i] == '1' && right.bin[i] == '0')
			//{
			//	if (temp)
			//	{
			//		C.bin[i] = '0';
			//		//temp--; 
			//	}
			//	else C.bin[i] = '1';

			//}
			//if (this->bin[i] == '0' && right.bin[i] == '0')
			//{
			//	if (temp)
			//	{
			//		C.bin[i] = '1';
			//		temp--;
			//	}
			//	else C.bin[i] = '0';
			//}
		}
		return C;
	}
	Binary(int size = 20) { this->size = size; this->bin = new char[size] {}; cout << "const: " << this << endl; }
	~Binary() { cout << "destructor: " << this << endl;/* delete[] bin;*/ }
	
		
	
	Binary& operator=(Binary& other)
	{
		this->size = other.size;
		this->bin = new char[size] {};
		strcpy(this->bin, other.bin);
		return *this;
	}
	Binary& operator~()
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->bin[i] == '1') this->bin[i] = '0';
			else this->bin[i] = '1';
		}
		return *this;
	}

		friend istream& operator>>(istream& in, Binary& other) { return in >> other.bin; }
	friend ostream& operator<<(ostream& out, const Binary& other) {	return out << other.bin << endl; }
	friend Binary& operator|(Binary& left, Binary& right);
	//friend Binary& operator+(Binary& left, Binary& right);
	friend int  bin_to_dec(Binary& other);
};

//Binary& operator+(Binary& left, Binary& right)
//{
//	int temp = 0;
//	Binary C(5);
//	for (int i = C.size-1; i >= 0; i--) {
//
//		if (left.bin[i] - 48 == 1 && right.bin[i] - 48 == 0 || left.bin[i] - 48 == 0 && right.bin[i] - 48 == 1)
//		{
//			if (!temp) C.bin[i] += 49;
//			else { C.bin[i] += 48; temp--; }
//		}
//		if (left.bin[i] - 48 == 0 && right.bin[i] - 48 == 0)
//		{
//
//			if (!temp) C.bin[i] += 48;
//			else { C.bin[i] += 49; temp--; }
//		}
//		if (left.bin[i] - 48 == 1 && right.bin[i] - 48 == 1) { C.bin[i] += 48; temp++; }
//
//	}
//	return C;
//}
int  bin_to_dec(Binary& other)
{
	int sum = 0;
	int k = strlen(other.bin);
	for (int i = 0; other.bin[i]; i++) {

		if (other.bin[i] != ' ') {
			sum += (other.bin[i] - '0') * pow(2, --k);
		}
	}
	return sum;
}
Binary& operator|(Binary& left, Binary& right)
{
	Binary temp;
	for (int i = 0; i < 4; i++)
	{
		if (!left.bin[i]== '1' || right.bin[i] == '1') temp.bin[i] = '1';/* { temp.bin[i] = '1'; }*/
		if (!left.bin[i] == '0' && right.bin[i] == '0') temp.bin[i] = '0';
			
	}
	return temp;
}
int main()
{
	setlocale(LC_ALL, "ru");
	Binary A, B, C;
	cin >> A; cin >> B;
    cout << A * B;
	//cout << C;
	/*int x = 0;
	int y = 1;
	int t = 0;
	int v = (x+y+t) % 2;
	cout << v;*/

	//char arr[] = "0110";
	/*char* a = new char[4];
	cin >> a;
	
	cout << a << endl;*/

	//cout << bin_to_dec(A);
	


	return 0;
}

