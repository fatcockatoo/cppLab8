#include "cppLAB8.h"
double Complex::getReal() const
{
	return this->real;
}

double Complex::getImaginary() const
{

	return this->imaginary;
}

void Complex::setReal(double real)
{
	this->real = real;
}
void Complex::setImaginary(double imaginary)
{
	this->imaginary = imaginary;
}

Complex::Complex(double real, double imaginary)
	:real(real), imaginary(imaginary) { }

ostream& operator << (ostream& stream, const Complex& z)
{
	if (z.getImaginary() >= 0)
	{
		stream << z.getReal() << "+" << z.getImaginary() << "*i";
	}
	else
	{
		stream << z.getReal() << z.getImaginary() << "*i";
	}
	return stream;
}


Complex operator +(Complex a, Complex b)
{
	return Complex(a.getReal() + b.getReal(), a.getImaginary() + b.getImaginary());
}

Complex operator *(Complex a, Complex b)
{
	return Complex(((a.getReal() * b.getReal()) - (b.getImaginary() * a.getImaginary())), ((a.getReal() * b.getImaginary()) + (b.getReal() * a.getImaginary())));
}

Complex tg(const Complex& z)
{
	return Complex(sin(2 * z.getReal()) / (cos(2 * z.getReal()) + cosh(2 * z.getImaginary())), (sinh(2 * z.getImaginary()) / (cos(2 * z.getReal()) + cosh(2 * z.getImaginary()))));
}
Complex operator -(Complex a, Complex b)
{
	return Complex(a.getReal() - b.getReal(), a.getImaginary() - b.getImaginary());
}

Complex operator /(Complex a, Complex b)
{
	return Complex(((a.getReal() * b.getReal()) - (a.getImaginary() * b.getImaginary() * (-1))) / (pow(b.getReal(), 2) + pow(b.getImaginary(), 2)), ((a.getReal() * b.getImaginary() * (-1)) + (a.getImaginary() * b.getReal())) / (pow(b.getReal(), 2) + pow(b.getImaginary(), 2)));
}
Complex y(const Complex& z)
{
	//return Complex(2, 0)*z + epp^5*(1+z);
	return Complex(2, 0) + z * tg(z);
}