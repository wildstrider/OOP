#include <iostream>
using namespace std;

class Box
{
	double height, width, depth;
	string material;
public:
	Box(string material, double height, double width, double depth)
	{
		this->depth = depth;
		this->height = height;
		this->width = width;
		this->material = material;
		cout << "Bconstructor" << this << endl;
	}
	~Box() { cout << "Destructor" << this << endl; }
	void Print()
	{
		cout << "Materieal: " << material << endl;
		cout << "Dimensions: " << height << "x" << width << "x" << depth << endl;
		cout << "Volume:     " << height * width * depth << endl;
	}
};
class GiftBox :public Box
{
	string cover;
public:
	GiftBox(string material, double height, double width, double depth, string cover): Box(material, height, width, depth)
		{ this->cover = cover; cout << "GBconstructor: " << this << endl; }
	~GiftBox() { cout << "GBDestructor: " << this << endl; }

};
int main()
{
	setlocale(LC_ALL, "ru");
	Box box("картон",3,4,5);
	box.Print();
	GiftBox giftbox("cardboard", 3, 4, 5, "With roses");
	giftbox.Print();
	return 0;
}