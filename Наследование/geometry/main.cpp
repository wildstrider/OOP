#define _USE_MATH_DEFINES
#include <iostream>
#include <Windows.h>
using namespace std;

namespace Geometry
{
	//typedef unsigned int Color;
	enum Color {
		console_black = 0x00,
		console_white = 0xff,
		console_red = 0xcc,
		console_green = 0xaa,
		console_blue = 9,
		default_consol_color = 0x07,

		black = 0x0000000,
		white = 0x00ffffff,
		red = 0x00000000ff,
		green = 0x0000ff00,
		yellow = 0x0000aaff,
		blue = 0x00ff0000,
	};

	class Shape
	{
	protected:
		Color color;
	public:
		Shape(Color color) :color(color) {}
		virtual ~Shape() {}
		virtual double get_areo() const = 0;
		virtual double get_perimeter() const = 0;
		virtual void draw() const = 0;
		virtual void info() const = 0;
	};

	class Square : public Shape
	{
		double side;
	public:
		double get_side() const {
			return side;
		}
		double set_side(double side)
		{
			if (side <= 0)side = 1;
			this->side = side;
			return side;
		}
		Square(Color color, double side) : Shape(color)/*, side(set_side(side))*/
		{
			set_side(side);
		}
		~Square() {}
		double get_areo() const { return side * side; }
		double get_perimeter() const { return side * 4; }
		void draw() const
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			unsigned int default_color;
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::default_consol_color);
		}
		void info()const
		{
			cout << "квадрат:\n";
			cout << "длинна стороны: " << side << endl;
			cout << "площадь: " << get_areo() << endl;
			cout << "периметр: " << get_perimeter() << endl;
			draw();
		}
	};

	class Rectangle : public Shape
	{
		double lenght;
		double wight;
	public:
		double get_lenght() const
		{
			return lenght;
		}
		double get_wight() const
		{
			return wight;
		}
		void set_lenght(double lenght)
		{
			if (lenght <= 0) lenght = 1;
			this->lenght = lenght;
		}
		void set_wight(double wight)
		{
			if (wight <= 0) wight = 1;
			this->wight = wight;
		}
		Rectangle(Color color, double lenght, double wight) :Shape(color)
		{
			set_lenght(lenght);
			set_wight(wight);
		}
		double get_areo() const
		{
			return lenght * wight;
		}
		double get_perimeter() const
		{
			return (lenght + wight) + 2;
		}
		void draw()const
		{
			HANDLE hConsol = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsol, color);
			for (int i = 0; i < lenght; i++)
			{
				for (int j = 0; j < wight; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsol, Color::default_consol_color);
		}
		void info()const
		{
			cout << "прямоугольник\n";
			cout << "длинна: " << lenght << endl;
			cout << "ширина: " << wight << endl;
			cout << "площадь: " << get_areo() << endl;
			cout << "периметр: " << get_perimeter() << endl;
			draw();
		}
		~Rectangle() {}

	};
	
	class Circle : public Shape
	{
		UINT start_x;
		UINT start_y;
		double radius;
	public:
		double get_radius() const { return radius; }
		double get_diameter() const { return radius * 2; }
		void set_radius(double radius)
		{
			if (radius <= 0) radius = 1;
			this->radius = radius;
		}
		void set_start_x(UINT x)
		{
			if (x >= 1000) x = 1000;
			start_x = x;
		}
		void set_start_y(UINT y)
		{
			if (y >= 700) y = 700;
			start_y = y;
		}
		Circle(Color color, double radius, UINT start_x = 0, UINT start_y = 0) : Shape(color)
		{
			set_radius(radius);
			set_start_x(start_x);
			set_start_y(start_y);
		}
		~Circle() {}
		double get_areo() const { return M_PI * pow(radius,2); }
		double get_perimeter() const { return 2 * M_PI * radius; }
		void draw() const 
		{
			//создаем
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hpen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(black);
			//рисуем
			SelectObject(hdc, hpen);
			SelectObject(hdc, hBrush);
			Ellipse(hdc, start_x, start_y, start_x + get_diameter(), start_y + get_diameter());
			// удаляем
			DeleteObject(hBrush);
			DeleteObject(hpen);
			ReleaseDC(hwnd, hdc);
		}
		void info() const 
		{
			cout << "круг\n";
			cout << "радиус: " << radius << endl;
			cout << "площадь периметр: " << get_areo() << endl;
			cout << "периметр: " << get_perimeter() << endl;
			draw();
		}
	};

	class Triangle : public Shape
	{
	  
	};
}
int main()
{
	setlocale(LC_ALL, "ru");
	COORD c = { 80,50 };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleDisplayMode(hConsole, 0/*CONSOLE_FULLSCREEN*/, &c);

	
	Geometry::Square square(Geometry::Color::console_red, 5);
	square.info();
	Geometry::Rectangle rectangle(Geometry::Color::console_green, 4, 8);
	rectangle.info();
	Geometry::Circle circle(Geometry::Color::yellow, 150, 200, 200);
	circle.info();

	return 0;
}