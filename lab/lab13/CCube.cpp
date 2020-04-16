//
// Created by 泫泫 on 2019/12/11.
//

#include <iostream>
#include "CCube.h"

CCube::CCube() {}

CCube::CCube(double len, double wid, double height) {
    this -> length = len;
    this -> width = wid;
    this -> height = height;
}

CCube::CCube(CCube &obj) {
    length = obj.length;
    width = obj.width;
    height = obj.height;
}

double CCube::GetArea() {
    return length * width;
}

double CCube::GetVolume() {
    return length * width * height;
}

void CCube::Show() {
    std::cout << "length: " << length << "\n"
              << "width: "  << width << "\n"
              << "height： " << height << "\n"
              << "surface area: " << GetArea() << "\n"
              << "volume: " << GetVolume() << "\n";
}



