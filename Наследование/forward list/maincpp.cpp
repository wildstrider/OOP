#include <iostream>
using namespace std;
#define tab "\t"

class Element
{
	int Data;
	Element* pNext;
public:
	Element(int Data, Element* pNext = nullptr) : Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this <<  endl;
	}
	friend class Forward_List;
};

class Forward_List
{
	Element* Head;
public:
	Forward_List()
	{
		this->Head = nullptr;
		cout << "LConstructor:\t" << this << endl;
	}
	~Forward_List()
	{
		cout << "LDestructor:\t" << this << endl;
	}
	// adding elemetns
	void push_front(int data)
	{
		Element* New = new Element(data);
		New->pNext = Head;
		Head = New;
	}
	void push_back(int data)
	{
		if(!Head) return push_front(data);
		
		Element* temp = Head;
		while (temp->pNext) { temp = temp->pNext; }
		temp->pNext = new Element(data);
	}
	void Print() const
	{
		Element* temp = Head;// temp это итератор 
		// итератор это указатель при помощи которого можно получить доступ к элементам структуры данных
		while (temp)
		{
			cout << temp << tab << temp->Data << tab << temp->pNext << endl;
			temp = temp->pNext;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	int n; cout << "Введите размер списка: "; cin >> n;
	Forward_List list;
	for(int i=0;i<n;i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.Print();
	/*list.push_back(123);
	list.Print();*/
	return 0;
}