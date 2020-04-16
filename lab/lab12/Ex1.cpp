////
//// Created by 泫泫 on 2019/11/28.
////

#include "Complex.h"
#include <iostream>

using namespace std;

Complex::Complex() {}
Complex::Complex(double re, double im) {
    this -> real = re;
    this -> imag = im;
}

Complex Complex::operator+(const Complex& other)const
{
    double result_real = real + other.real;
    double result_imag = imag + other.imag;

    return Complex(result_real,result_imag);
}

Complex Complex::operator-(const Complex& other)const
{
    double result_real = real - other.real;
    double result_imag = imag - other.imag;

    return Complex(result_real,result_imag);
}

Complex Complex::operator*(const Complex& other)const
{
    double result_real = real * other.real + imag * other.imag * (-1);
    double result_imag = real * other.imag + imag * other.real;

    return Complex(result_real,result_imag);
}

Complex operator*(int add,const Complex& other)
{
    double result_real = add * other.real;
    double result_imag = add * other.imag;

    return Complex(result_real,result_imag);
}

Complex Complex::operator~()
{
    double result_imag = (-1) * imag;

    return Complex(real,result_imag);
}

int operator==(const Complex& a, const Complex& b)
{
    int result = 1;
    if(a.real != b.real || a.imag != b.imag){
        result = 0;
    }

    return result;
}

int operator!=(const Complex& a, const Complex& b)
{
    int result = 0;
    if(a.real == b.real || a.imag == b.imag){
        result = 1;
    }

    return result;
}

std::ostream & operator<<(std::ostream& os,const Complex& other)
{
    os << other.real << "+" << other.imag << "i";
    return os;
}

std::istream & operator>>(std::istream& is,Complex& other)
{
    cout << "real: ";
    is >> other.real;
    cout << "imaginary: ";
    is >> other.imag;
}


int main()
{
    Complex a(3.0, 4.0);
    Complex b(2.0,6.0);

    cout << "b is " << b << endl;
    cout << "~b is " << ~b << endl;
    cout << "a is " << a << endl;
    cout << "a + b is " << a + b << endl;
    cout << "a - b is " << a - b << endl;
    cout << "a * b is " << a * b << endl;
    cout << "2 * b is " << 2 * b << endl;

    Complex c=b;
    cout<< "b==c is "<<(b==c)<<endl;
    cout<<"b!=c is"<< (b!=c)<<endl;
    cout<<"a==c is"<<(a==c)<<endl<<endl;

    Complex d;
    cout << "Enter a complex number : " << endl;
    cin >> d;
    cout << "d is " << d << endl;

    return 0;
}
