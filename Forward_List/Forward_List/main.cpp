#include <iostream>
using namespace std;

template<typename T> class ForwardList
{
	template<typename T> class Element
	{
	public:
		T Data;
		Element* pNext;
		Element(T Data = T(), Element* pNext = nullptr) : Data(Data), pNext(pNext) {}
		~Element() {}
	};
	Element<T>* Head;
	int size;
public:
	int get_size() const { return size; }
	ForwardList() :size(0), Head(nullptr) {}
	T& operator[](const int index)
	{
		int count = 0;
		Element<T>* temp = this->Head;
		while (temp)
		{
			if (count == index) return temp->Data;
			temp = temp->pNext;
			count++;
		}
	}
	void push_front(T data) { Head = new Element<T>(data, Head); size++; }
	void push_back(T data)
	{
		if (!Head) { return push_front(data); }
		Element<T>* temp = Head;
		while (temp->pNext) { temp = temp->pNext; }
		temp->pNext = new Element<T>(data);
		size++;
	}
	void insert(int const index, T data)
	{
		if (!index)return push_front(data);
		Element<T>* temp = Head;
		for (int i = 0; i < index - 1; temp = temp->pNext, i++);
		temp->pNext = new Element<T>(data, temp->pNext);
		size++;
	}
	void pop_front()
	{
		Element<T>* temp = Head;
		Head = Head->pNext;
		delete temp;
		size--;
	}
	void erease(const int index)
	{
		if (!index)return pop_front();
		Element<T>* temp = Head;
		for (int i = 0; i < index - 1; temp = temp->pNext, i++);
		Element<T>* toDelete = temp->pNext;
		temp->pNext = toDelete->pNext;
		delete toDelete;
		size--;
	}
	void pop_back() { erease(size - 1); }
	void clear() { while (size) pop_front(); }
	~ForwardList() { clear(); }
};

int main()
{
	setlocale(LC_ALL, "ru");
	ForwardList<int> list;
	int s; cout << "Введите размер массива: "; cin >> s;
	//list.push_front(9);
	for (int i = 0; i < s; list.push_back(i), i++);
	//list.insert(3, 58);
	//list.pop_front();
	//list.erease(3);
	//list.pop_back();
	for (int i = 0; i < list.get_size(); cout << "index [" << i << "] " << list[i] << endl, i++);
	cout << endl;
	cout << list.get_size() << endl;
	return 0;
}