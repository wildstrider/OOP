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
	int numerator;
    int denominator;	
public:
	int GetNumerator() const { return numerator; }
	int GetDenominator() const { return denominator; }
	void SetNumenator(int numenator) { this->numerator = numenator; }
	void SetDenominator(int denominator) { this->denominator = denominator; }
	void Print() const { cout << this->GetNumerator() << '/' << this->GetDenominator() << endl; }
	Fraction& operator++()//++Fraction
	{
		Fraction fracTemp(this->GetDenominator(), this->GetDenominator());
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
	Fraction(int numerator = 1, int denominator = 2)
	{
		this->numerator = numerator;
		this->denominator = denominator;
	}
	~Fraction() {}
	friend ostream& operator<<(ostream& out, Fraction& other) { return out << other.numerator << '/' << other.denominator; }
	friend istream& operator>>(istream& in, Fraction& other)
	{
		cout << "Введите числитель: ";
		in >> other.numerator;
		cout << "Введите знаменатель: ";
		in >> other.denominator;
		return in;
	}
};


void FractionReduction(Fraction& other)
{
	for (int i = other.GetNumerator(); i > 0; i--) {

		if (other.GetNumerator() % i == 0 && other.GetDenominator() % i == 0) {
			other.SetNumenator(other.GetNumerator() / i);
			other.SetDenominator(other.GetDenominator() / i);
			break;
		}
	}
}
Fraction operator+(const Fraction& fraction_1, const Fraction& fraction_2)
{
	Fraction fracTemp;
	if (fraction_1.GetDenominator() == fraction_2.GetDenominator())
	{
		fracTemp.SetNumenator(fraction_1.GetNumerator() + fraction_2.GetNumerator());
		fracTemp.SetDenominator(fraction_1.GetDenominator());
	}
	else
	{
		fracTemp.SetNumenator((fraction_1.GetNumerator() * fraction_2.GetDenominator()) + (fraction_2.GetNumerator() * fraction_1.GetDenominator()));
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
		fracTemp.SetNumenator(fraction_1.GetNumerator() - fraction_2.GetNumerator());
		fracTemp.SetDenominator(fraction_1.GetDenominator());
	}
	else
	{
		fracTemp.SetNumenator((fraction_1.GetNumerator() * fraction_2.GetDenominator()) - (fraction_2.GetNumerator() * fraction_1.GetDenominator()));
		fracTemp.SetDenominator(fraction_1.GetDenominator() * fraction_2.GetDenominator());
	}
	FractionReduction(fracTemp);
	return fracTemp;
}
Fraction operator*(const Fraction& fraction_1, const Fraction& fraction_2)
{
	Fraction fracTemp;
	fracTemp.SetNumenator(fraction_1.GetNumerator() * fraction_2.GetNumerator());
	fracTemp.SetDenominator(fraction_1.GetDenominator() * fraction_2.GetDenominator());
	FractionReduction(fracTemp);
	return fracTemp;
}
Fraction operator/(const Fraction& fraction_1, const Fraction& fraction_2)
{
	Fraction fracTemp;
	fracTemp.SetNumenator(fraction_1.GetNumerator() * fraction_2.GetDenominator());
	fracTemp.SetDenominator(fraction_1.GetDenominator() * fraction_2.GetNumerator());
	FractionReduction(fracTemp);
	return fracTemp;
}
bool operator==(const Fraction& fraction_1, const Fraction& fraction_2)
{ return fraction_1.GetNumerator() == fraction_2.GetNumerator() && fraction_1.GetDenominator() == fraction_2.GetDenominator(); }
bool operator!=(const Fraction& fraction_1, const Fraction& fraction_2)
{ return !(fraction_1.GetNumerator() == fraction_2.GetNumerator() && fraction_1.GetDenominator() == fraction_2.GetDenominator()); }

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
	fraction_3 ++;
	cout << fraction_3 << endl;
	return 0;
}

	