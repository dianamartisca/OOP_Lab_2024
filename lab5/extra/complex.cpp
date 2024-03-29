#include "complex.h"

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex& Complex::operator()(double real, double imag)
{
    real_data = real;
    imag_data = imag;
    return (*this);
}

Complex operator+(const Complex& l, const Complex& r)
{
    return { l.real() + r.real(), l.imag() + r.imag() };
}

Complex operator+(const Complex& l, double r)
{
    return { l.real() + r,l.imag() };
}

Complex operator+(double r, const Complex& l)
{
    return { l.real() + r,l.imag() };
}

Complex operator-(const Complex& l, const Complex& r)
{
    return { l.real() - r.real(), l.imag() - r.imag() };
}

Complex operator-(const Complex& l, double r)
{
    return { l.real() - r,l.imag() };
}

Complex operator-(double r, const Complex& l)
{
    return { l.real() - r,l.imag() };
}

Complex operator*(const Complex& l, const Complex& r)
{
    return { l.real() * r.real() - l.imag() * r.imag(), r.real() * l.imag() + r.imag() * l.real() };
}

Complex operator*(const Complex& l, double r)
{
    return { l.real() * r,l.imag() * r };
}

Complex operator*(double r, const Complex& l)
{
    return { l.real() * r,l.imag() * r };
}

Complex operator-(const Complex& obj)
{
    return { -obj.real(),-obj.imag() };
}

bool operator==(const Complex& l, const Complex& r)
{
    return (l.real() == r.real() && l.imag() == r.imag());
}

bool operator!=(const Complex& l, const Complex& r)
{
    return (l.real() != r.real() || l.imag() != r.imag());
}

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
    if (complex.real() == 0 && complex.imag() == 0)
        out << 0;
    else
    {
        if (complex.real() == 0)
            out << complex.imag() << "i";
        else
            if (complex.imag() == 0)
                out << complex.real();
            else
                if (complex.imag() < 0)
                    out << complex.real() << complex.imag() << "i";
                else
                    out << complex.real() << "+" << complex.imag() << "i";
    }
    out << '\n';
    return out;
}

Complex& operator++(Complex& obj)
{
    return obj(obj.real() + 1, obj.imag());
}

Complex operator++(Complex& obj, int x)
{
    return (++obj);
}

Complex& operator--(Complex& obj)
{
    return obj(obj.real() - 1, obj.imag());
}

Complex operator--(Complex& obj, int x)
{
    return (--obj);
}