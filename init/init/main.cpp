#include <iostream>
#include <cmath>
using namespace std;
#define tab "\t"
//#define CONSTRUCTOR
class Point 
{
private:
	double x;
	double y;
public:
	double get_x() const{ return x; }
	double get_y() const{ return y; }
	void set_x(double x){ this->x = x; }
	void set_y(double y){ this->y = y; }

#ifdef CONSTRUCTOR
	Point()
	{
		x = y = 0;
		cout << "defaultconstructor: \t" << this << endl;
	}
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

	void Print()
	{
		cout << "X = " << x << tab << "Y = " << y << endl;
	}
	double DistanceToPoint()
	{
		 return sqrt(pow(x, 2) + pow(y, 2));
	}
};

double DistanceBetweenPoints(Point A, Point B);
//#define STRICT	
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

	Point A; 
	A.set_x(-1);
	A.set_y(3);
	//cout << A.get_x() << tab << A.get_y() << endl;
	
	Point B;
	B.set_x(6);
	B.set_y(2);
	//B.Print();
	//Point C = A; // copyconstructor
	cout << "Расстояние до точки A - " << B.DistanceToPoint() << endl;
	cout << "Расстояние от точки A до точки В - " << DistanceBetweenPoints(A,B) << endl;
	Point g;
	return 0;
}
double DistanceBetweenPoints(Point A, Point B)
{
	return sqrt(pow((B.get_x() - A.get_x()), 2) + pow((B.get_y() - A.get_y()), 2));
}