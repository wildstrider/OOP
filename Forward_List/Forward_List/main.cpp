#include <iostream>
using namespace std;

template<typename T> class ForwardList
{
	template<typename T> class Element
	{
	public:
		T Data;
		Element* pNext;
		Element( T Data = T(), Element* pNext = nullptr) :  Data(Data), pNext(pNext) {}
		~Element() {}
	};
	Element<T>* Head;
	size_t size;
public:
	int get_size() const { return size; }
	void set_Data(T Data) { this->Data = Data; }
	ForwardList() :size(0), Head(nullptr) {}
	explicit ForwardList(size_t size) { for (int i = 0; i < size; push_back(0), i++); }
	/*ForwardList(ForwardList& other)
	{
		this->size = 0;
		Element<T>* Temp = other.Head;
		for(int i= 0;i < other.size;i++)
		{
			 push_back(Temp->Data);
			 Temp = Temp->pNext;
		}
	}*/
	T& operator[](const size_t index)
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
	//ForwardList operator=(T s) { this->set_Data(s); }
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
		if (index > size)return;
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
	ForwardList& operator=(const ForwardList& other)
	{
		if (this == &other)return *this;
		clear();
		for (Element<T>* temp = other.Head; temp; temp->temp->pNext) push_back(temp->Data);
		/*Element<T>* temp = other.Head;
		while (temp)
		{
			push_back(temp->Data);
			temp = temp->pNext;
		}*/
		cout << "LCopyEssigment: " << this << endl;
		return *this;
	}
	ForwardList(const ForwardList& other) :ForwardList()
	{
		for(Element<T>* temp = other.Head;temp;temp->pNext) push_back(temp->Data);
		/*Element<T>* temp = other.Head;
		while (temp)
		{
			push_back(temp->Data);
			temp = temp->pNext;
		}*/
		cout << "LCopiConstructor: " << this << endl;
	}
	~ForwardList() { clear(); }
};
//#define COPY
#define BASE
int main()
{
	setlocale(LC_ALL, "ru");
#ifdef BASE
	ForwardList<int> list;
	int s; cout << "Введите размер массива: "; cin >> s;
	//list.push_front(9);
	for (int i = 0; i < s; list.push_back(i), i++);
	//list.insert(3, 58);
	//list.pop_front();
	//list.erease(3);
	for (int i = 0; i < list.get_size(); list[i] = rand() % 100, i++);
	list.pop_back();
	for (int i = 0; i < list.get_size(); cout << "index [" << i << "] " << list[i] << endl, i++);
	cout << endl;
	cout << list.get_size() << endl;
	ForwardList<int> list2(5);
	for (int i = 0; i < list2.get_size(); cout << "index [" << i << "] " << list2[i] << endl, i++);
	for (int i = 0; i < list2.get_size(); list2[i] = rand() % 100, i++);
	for (int i = 0; i < list2.get_size(); cout << "index [" << i << "] " << list2[i] << endl, i++);
	ForwardList<int> list3 = list2;
	for (int i = 0; i < list3.get_size(); cout << "index [" << i << "] " << list3[i] << endl, i++);
#endif // BASE

#ifdef COPY
	ForwardList<int> list;
	list.push_back(3);
	list.push_back(5);
	list.push_back(8);
	list.push_back(13);
	list.push_back(21);
	list = list;
	for (int i = 0; i < list.get_size(); cout << "index [" << i << "] " << list[i] << endl, i++);
	//list.print();

	ForwardList<int> list2 = list;
	for (int i = 0; i < list2.get_size(); cout << "index [" << i << "] " << list2[i] << endl, i++);
	//list2.print();



	//ForwardList<int> list3;
	//list3 = list2;
	//for (int i = 0; i < list3.get_size(); cout << "index [" << i << "] " << list3[i] << endl, i++);  
#endif // COPY
	

	return 0;
}