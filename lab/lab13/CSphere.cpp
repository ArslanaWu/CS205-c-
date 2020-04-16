//
// Created by 泫泫 on 2019/12/11.
//

#include <iostream>
#include "CSphere.h"

CSphere::CSphere() {
}

CSphere::CSphere(double radius) {
    this -> radius = radius;
}

CSphere::CSphere(CSphere &obj) {
    radius = obj.radius;
}

double CSphere::GetArea() {
    return 3.14 * radius * radius;
}

double CSphere::GetVolume() {
    return 4 / 3 * 3.14 * radius * radius * radius;
}

void CSphere::Show() {
    std::cout << "radius: " << radius << "\n"
              << "surface area: " << GetArea() << "\n"
              << "volume: " << GetVolume() << "\n";
}

