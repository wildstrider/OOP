#include <iostream>
using namespace std;
#define tab "\t"
class Fraction;

Fraction operator+(const Fraction& fraction_1, const Fraction& fraction_2);
Fraction operator-(const Fraction& fraction_1, const Fraction& fraction_2);
Fraction operator*(const Fraction& fraction_1, const Fraction& fraction_2);
Fraction operator/(const Fraction& fraction_1, const Fraction& fraction_2);

class Fraction
{
	int integer = 0;
	int numerator;
    int denominator;	
	double Double = 0;
	int sum;
public:
	int GetNumerator() const { return numerator; }
	int GetDenominator() const { return denominator; }
	int GetInteger() const { return integer; }
	double GetDouble() const { return Double; }
	int GetSum() const { return sum; }
	void SetDuoble(int numerator, int denominator) { this->Double = (double)numerator / (double)denominator + integer; }
	void SetNumenator(int numenator) { this->numerator = numenator; }
	void SetDenominator(int denominator) { this->denominator = denominator; }
	void SetInteger(int integer) { this->integer = integer; }
	void Print() const { cout << this->GetNumerator() << '/' << this->GetDenominator() << endl; }
	Fraction& operator++()//++Fraction
	{
		Fraction fracTemp(0, this->GetDenominator(), this->GetDenominator());
		return *this = *this + fracTemp;
	}
	Fraction operator++(int)//Fraction++ 
	{
		Fraction old = *this;
		++*this;
		return old;
	}
	Fraction& operator--()//--Fraction
	{
		Fraction fracTemp(this->GetDenominator(), this->GetDenominator());
		return *this = *this - fracTemp;
	}
	Fraction operator--(int)//Fraction--
	{
		Fraction old = *this;
		--* this;
		return old;
	}
	Fraction& operator+=(const Fraction& other) { return *this = *this + other; }
	Fraction& operator-=(const Fraction& other) { return *this = *this - other; }
	Fraction& operator*=(const Fraction& other) { return *this = *this * other; }
	Fraction& operator/=(const Fraction& other) { return *this = *this / other; }
	Fraction(int integer = 0, int numerator = 1, int denominator = 2)
	{
		if (integer) this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		//this->sum = this-> GetInteger()? this ->GetInteger() * this->GetDenominator() + this->GetNumerator() : this->GetDenominator() + this->GetNumerator();
	}
	~Fraction() {}
	friend ostream& operator<<(ostream& out, const  Fraction& other)
	{
		if (!other.GetInteger()) return out << other.GetNumerator() << '/' << other.GetDenominator() << " ( " << other.GetDouble() << " )";
		if (!other.GetDouble()) return out << other.GetInteger() << ' ' << other.GetNumerator() << '/' << other.GetDenominator();
		if (other.GetDenominator() < 2 || other.GetNumerator() < 1) return out << other.GetInteger() << " ( " << other.GetDouble() << " )";
		else return out << other.GetInteger() << ' ' << other.GetNumerator() << '/' << other.GetDenominator() << "( " << other.GetDouble() << " )";
	}
	friend istream& operator>>(istream& in, Fraction& other)
	{
		cout << "Введите целое число: "; in >> other.integer;
		cout << "Введите числитель: ";   in >> other.numerator;
		cout << "Введите знаменатель: "; in >> other.denominator;
		return in;
	}
};

Fraction FractionReduction(Fraction& other)
{
	for (int i = other.GetNumerator() < 0? -other.GetNumerator(): other.GetNumerator(); i > 0; i--) {

		if (other.GetNumerator() % i == 0 && other.GetDenominator() % i == 0) {
			other.SetNumenator(other.GetNumerator() / i);
			other.SetDenominator(other.GetDenominator() / i);
			break;
		}
	}
	if (other.GetNumerator() > other.GetDenominator())
	{
		int remainder = other.GetNumerator() % other.GetDenominator();
		other.SetInteger(other.GetNumerator() / other.GetDenominator());
		other.SetNumenator(remainder);
	}
	other.SetDuoble(other.GetNumerator(), other.GetDenominator());
	return other;
}
Fraction operator+(const Fraction& fraction_1, const Fraction& fraction_2)
{
	Fraction fracTemp;
	if (fraction_1.GetDenominator() == fraction_2.GetDenominator())
	{

		fracTemp.SetNumenator((fraction_1.GetInteger() * fraction_1.GetDenominator() + fraction_1.GetNumerator()) +
			(fraction_2.GetInteger() * fraction_2.GetDenominator() + fraction_2.GetNumerator()));
		fracTemp.SetDenominator(fraction_1.GetDenominator());
	}
	else
	{
		fracTemp.SetNumenator((fraction_2.GetDenominator() * (fraction_1.GetInteger() * fraction_1.GetDenominator() + fraction_1.GetNumerator())) +
			(fraction_1.GetDenominator() * (fraction_2.GetInteger() * fraction_2.GetDenominator() + fraction_2.GetNumerator())));
		fracTemp.SetDenominator(fraction_1.GetDenominator() * fraction_2.GetDenominator());
	}
	FractionReduction(fracTemp);
	return fracTemp;
}
Fraction operator-(const Fraction& fraction_1, const Fraction& fraction_2)
{

	Fraction fracTemp;
	if (fraction_1.GetDenominator() == fraction_2.GetDenominator())
	{
		fracTemp.SetNumenator((fraction_1.GetInteger() * fraction_1.GetDenominator() + fraction_1.GetNumerator())-
			(fraction_2.GetInteger() * fraction_2.GetDenominator() + fraction_2.GetNumerator()));
		fracTemp.SetDenominator(fraction_1.GetDenominator());
	}
	else
	{
		fracTemp.SetNumenator((fraction_2.GetDenominator() * (fraction_1.GetInteger() * fraction_1.GetDenominator() + fraction_1.GetNumerator())) -
			(fraction_1.GetDenominator() * (fraction_2.GetInteger() * fraction_2.GetDenominator() + fraction_2.GetNumerator())));
		fracTemp.SetDenominator(fraction_1.GetDenominator() * fraction_2.GetDenominator());
	}
	FractionReduction(fracTemp);
	return fracTemp;
}
Fraction operator*(const Fraction& fraction_1, const Fraction& fraction_2)
{
	Fraction fracTemp;
	fracTemp.SetNumenator((fraction_1.GetInteger() * fraction_1.GetDenominator() + fraction_1.GetNumerator()) *
			(fraction_2.GetInteger() * fraction_2.GetDenominator() + fraction_2.GetNumerator()));
	fracTemp.SetDenominator(fraction_1.GetDenominator() * fraction_2.GetDenominator());
	FractionReduction(fracTemp);
	return fracTemp;
}
Fraction operator/(const Fraction& fraction_1, const Fraction& fraction_2)
{
	Fraction fracTemp;
	int _numerator = fraction_1.GetInteger() * fraction_1.GetDenominator() + fraction_1.GetNumerator();
	int _denominator = fraction_2.GetInteger() * fraction_2.GetDenominator() + fraction_2.GetNumerator();
	fracTemp.SetNumenator(_numerator * fraction_2.GetDenominator());
	fracTemp.SetDenominator(fraction_1.GetDenominator() * _denominator);
	FractionReduction(fracTemp);
	return fracTemp;
}
bool operator==(const Fraction& fraction_1, const Fraction& fraction_2)
{ return fraction_1.GetNumerator() * fraction_2.GetDenominator() == fraction_1.GetDenominator() * fraction_2.GetNumerator() && 
         fraction_1.GetInteger() == fraction_2.GetInteger() ; }
bool operator!=(const Fraction& fraction_1, const Fraction& fraction_2)
{ return !(fraction_1 == fraction_2); }
bool operator<(const Fraction& fraction_1, const Fraction& fraction_2)
{ return fraction_1.GetNumerator() * fraction_2.GetDenominator() < fraction_1.GetDenominator() * fraction_2.GetNumerator() ||
	     fraction_1.GetInteger() < fraction_2.GetInteger(); }
bool operator<=(const Fraction& fraction_1, const Fraction& fraction_2) { return fraction_1 == fraction_2 || fraction_1 < fraction_2; }
bool operator>(const Fraction& fraction_1, const Fraction& fraction_2)
{ return fraction_1.GetNumerator() * fraction_2.GetDenominator() > fraction_1.GetDenominator() * fraction_2.GetNumerator() ||
         fraction_1.GetInteger() > fraction_2.GetInteger(); }
bool operator>=(const Fraction& fraction_1, const Fraction& fraction_2) { return fraction_1 == fraction_2 || fraction_1 > fraction_2; }

int main()
{
	setlocale(LC_ALL, "ru");
	Fraction fraction_1, fraction_2, fraction_3;
	cout << "fraction_1" << endl; cin >> fraction_1;
	cout << "fraction_2" << endl; cin >> fraction_2;
	cout << "Выберите действие +-*/ " << endl; char sign; cin >> sign;

	switch (sign)
	{
	case '+': fraction_3 = fraction_1 + fraction_2; break;
	case '-': fraction_3 = fraction_1 - fraction_2; break;
	case '*': fraction_3 = fraction_1 * fraction_2; break;
	case '/': fraction_3 = fraction_1 / fraction_2; break;
	}
	cout << fraction_1 << sign << fraction_2 << " = " << fraction_3 << endl;
	fraction_3++;
	bool flag = fraction_1 < fraction_2;
	cout << fraction_3 << endl;
	cout << flag;
	return 0;
}

	