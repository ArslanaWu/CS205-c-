//
// Created by 泫泫 on 2019/11/28.
//

#ifndef EXAMPLE_COMPLEX_H
#define EXAMPLE_COMPLEX_H

#include <iostream>

class Complex
{
public:
    Complex();
    Complex(double re,double im);

    Complex operator+(const Complex& other)const;
    Complex operator-(const Complex& other)const;
    Complex operator*(const Complex& other)const;
    friend Complex operator*(int add,const Complex& other);
    Complex operator~();

    friend int operator==(const Complex& a, const Complex& b);
    friend int operator!=(const Complex& a, const Complex& b);

    friend std::ostream & operator<<(std::ostream& os,const Complex& other);
    friend std::istream & operator>>(std::istream& is,Complex& other);


private:
    double imag;
    double real;

};

#endif //EXAMPLE_COMPLEX_H
