//
// Created by 泫泫 on 2019/12/11.
//

#include "CStereoShape.h"

int CStereoShape::numberOfObject=0 ;


CStereoShape::CStereoShape() {
    numberOfObject++;
}

double CStereoShape::GetArea() {
    return 0.0;
}

double CStereoShape::GetVolume() {
    return 0.0;
}

void CStereoShape::Show() {}

int CStereoShape::GetNumOfObject() {
    return numberOfObject;
}



