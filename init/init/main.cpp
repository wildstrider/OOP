#include <iostream>
#include <cmath>
using namespace std;
#define tab "\t"
#define hello(arg) "hello "#arg

#define CONSTRUCTOR
#define delimeter "\n====================================================\n"
class Point
{
private:
	double x;
	double y;
public:
	double get_x() const { return x; }
	double get_y() const { return y; }
	void set_x(double x) { this->x = x; }
	void set_y(double y) { this->y = y; }

#ifdef CONSTRUCTOR
	/*Point()
	{
		x = y = 0;
		cout << "defaultconstructor: \t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "Copyconstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "destructor: \t" << this << endl;
	}
#endif 
	Point& operator= (const Point& other) {
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}
	/*Point operator+(const Point& other) const
	{
		Point result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;
		cout << "operator+:\t" << this << endl;
		return result;
	}*/
	Point& operator++()//++c
	{
		this->x++;
		this->y++;
		cout << "increment:\t" << this << endl;
		return *this;
	}
	Point operator++(int)//c++
	{
		Point old = *this;
		this->y++;
		this->x++;
		cout << "suffix incremrnt" << endl;
		return old;
	}
	void Print()
	{
		cout << "X = " << x << tab << "Y = " << y << endl;
	}
	double DistanceToPoint(const Point &other) const
	{
		return sqrt(pow((other.get_x() - this->get_x()), 2) + pow((other.get_y() - this->get_y()), 2));
	}
};

double DistanceBetweenPoints(const Point &A, const Point &B);
Point operator+(const Point& left, const Point& right);
//#define STRICT	
//#define distance_and_constructors
//#define ASSIGMENT_CHECK
int main()
{
	setlocale(LC_ALL, "ru");

#ifdef STRUCT
	Point A; //создание обьекта
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;
	Point* pA = &A;
	cout << pA->x << tab << pA->y << endl;
#endif 

#ifdef distance_and_constructors
	Point A(1, 3);
	//A.set_x(1);
	//A.set_y(3);
	//cout << A.get_x() << tab << A.get_y() << endl;

	Point B(2, 6);
	//B.Print();
	Point C = A; // copyconstructor

	cout << delimeter << endl;
	cout << "Расстояние до точки B - " << A.DistanceToPoint(B) << endl;
	cout << "Расстояние до точки A - " << B.DistanceToPoint(A) << endl;
	cout << "Расстояние от точки A до точки В - " << DistanceBetweenPoints(A, B) << endl;
	cout << "Расстояние от точки A до точки В - " << DistanceBetweenPoints(B, A) << endl;
	cout << delimeter << endl;
	//cout << delimeter << endl;
	Point E = A;
	Point F;
	F = B;
	cout << delimeter << endl;
#endif 
#ifdef ASSIGMENT_CHECK
	Point A, B, C;
	cout << delimeter << endl;
	A = B = C = Point(2.3, 4.5);
	cout << delimeter << endl;
	A.Print();
	B.Print();
	C.Print();
	cout << delimeter << endl;
#endif // ASSIGMENT_CHECK

	//cout << hello(guy) << endl;
	Point A(2.3, 4.5);
	Point B(2.7, 3.14);
	Point C = A + B;
	C.Print();
	C++;
	C.Print();
	++C;
	C.Print();

	return 0;
}
double DistanceBetweenPoints(const Point &A, const Point &B)
{
	return sqrt(pow((B.get_x() - A.get_x()), 2) + pow((B.get_y() - A.get_y()), 2));
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	cout << "global plus" << endl;
	return result;
}