#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	const int n = 5;
	int arr[] = { 3,5,8,13,21 };
	cout << *arr << endl;
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)
	{
		cout << *(arr + i) << endl;
	}
	cout << endl;



	return 0;
}