#include <iostream>
using namespace std;
#define tab "\t"

template<typename T> class RoundTripList
{
	template<typename T> class Element
	{
	public:
		T Data;
		Element* pNext;
		Element* Prev;
		Element(T Data, Element* pNext = nullptr, Element* Prev = nullptr) : Data(Data), pNext(pNext), Prev(Prev)
		{
			cout << "EConstructor: " << this << endl;
		}
		~Element() { cout << "EDestructor: " << this << endl; }
	};
	Element<T>* Head;
	Element<T>* Tail;
	size_t size;
public:
	RoundTripList() : size(0), Head(nullptr), Tail(nullptr) { cout << "LConstructor: " << this << endl; }
	void push_front(T Data)
	{
		if (Head != nullptr)
		{
			Head = new Element<T>(Data, Head);
			Head->pNext->Prev = Head;
			size++;
		}
		else
		{
			Element<T>* New = new Element<T>(Data, Tail, Head);
			Head = Tail = New;
			size++;
		}
	}
	void push_back(T Data)
	{
		if (Tail != nullptr)
		{
			Tail = new Element<T>(Data, nullptr, Tail);
			Tail->Prev->pNext = Tail;
			size++;
		}
		else push_front(Data);
	}
	void pop_front()
	{
		if (Head != Tail)
		{
			Element<T>* temp = Head;
			Head = Head->pNext;
			Head->Prev = nullptr;
			delete temp;
			size--;
		}
		else
		{
			Element<T>* temp = Head;
			Head = Tail = nullptr;
			delete temp;
			size--;
		}
	}
	void pop_back()
	{
		if (Head != Tail)
		{
			Element<T>* temp = Tail;
			Tail = Tail->Prev;
			Tail->pNext = nullptr;
			delete temp;
			size--;
		}
		else pop_front();
	}
	void insert(const size_t index, T Data)
	{
		if (index > size) return;
		if (index == 0) return push_front(Data);
		if (index == size) return push_back(Data);
		if (index > size / 2 || index == size / 2)
		{
			Element<T>* temp = Tail;
			for (int i = size; i > index + 1; temp = temp->Prev, i--);
			temp->Prev = new Element<T>(Data, temp->Prev->pNext, temp->Prev);
			temp->Prev->Prev->pNext = temp->Prev;
			size++;
		}
		else
		{
			Element<T>* temp = Head;
			for (int i = 0; i < index - 1; temp = temp->pNext, i++);
			temp->pNext = new Element<T>(Data, temp->pNext, temp->pNext->Prev);
			temp->pNext->pNext->Prev = temp->pNext;
			size++;
		}
	}
	void erase(const size_t index)
	{
		Element<T>* temp;
		if (index > size - 1) return;
		if (index == 0) return pop_front();
		if (index == size - 1) return pop_back();
		if (index > size / 2 || index == size / 2) { temp = Tail; for (int i = size - 1; i > index; temp = temp->Prev, i--); }
		else { temp = Head; for (int i = 0; i < index; temp = temp->pNext, i++); }
		temp->pNext->Prev = temp->Prev;
		temp->Prev->pNext = temp->pNext;
		delete temp;
		size--;
	}
	void PrintHead() const
	{
		for(Element<T>* temp = Head; temp; temp=temp->pNext)
		cout << "Head: " << temp << " Prev: " << temp->Prev << tab << temp->Data << tab << "pNext: " << temp->pNext << " Tail: " << Tail << endl;
		cout << "размер list: " << size << endl;
	}
	void PrintTail() const
	{
		for(Element<T>* temp = Tail; temp; temp= temp->Prev)
		cout << "Head: " << temp << " Prev: " << temp->Prev << tab << temp->Data << tab << "pNext: " << temp->pNext << " Tail: " << Tail << endl;
		cout << "размер list: " << size << endl;
	}
	~RoundTripList() { while (Head) pop_front(); cout << "LDetructor: " << this << endl; }
};

int main()
{
	setlocale(LC_ALL, "ru");
	RoundTripList<int> list;
	list.push_front(10);
	list.push_front(150);
	list.push_front(14);
	list.push_front(1);
	list.push_back(55);
	//list.push_back(60);
	//list.push_back(5);
	//list.pop_front();
	//list.pop_back();
	list.PrintHead();
	//list.insert(4, 500);
	//list.insert(2, 350);
	list.erase(3);
	list.PrintHead();
	cout << endl;
	list.PrintTail();
	return 0;
}