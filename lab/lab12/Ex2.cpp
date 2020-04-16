//
// Created by 泫泫 on 2019/11/28.
//

#include <iostream>
#include "Number.h"

using namespace std;

Number::Number() {
    number = 0;
}

Number::Number(int num) {
    this -> number = num;
}

std::ostream &operator<<(std::ostream &os, const Number &other) {
    os << "x = " << other.number;
    return os;
}

int Number::operator++() {
    number++;
    return number;
}

int Number::operator--() {
    number--;
    return number;
}

int Number::operator++(int) {
    number++;
    return number - 1;
}

int Number::operator--(int) {
    number--;
    return number + 1;
}




int main()
{
    Number n1(20);

    Number n2 = n1++;
    cout << n1<<endl;
    cout << n2<<endl;

    Number n3 = n2--;
    cout << n2<<endl;
    cout << n3<<endl;

    Number n4 = ++n3;
    cout << n3 << endl;
    cout << n4 << endl;

    Number n5 = --n4;
    cout << n4 << endl;
    cout << n5 << endl;

    return 0;
}