//
// Created by 泫泫 on 2019/12/11.
//

#ifndef LAB13_CCUBE_H
#define LAB13_CCUBE_H

#include "CStereoShape.h"

class CCube : public CStereoShape{
private:
    double length = 0;
    double width = 0;
    double height = 0;
    double area;
    double volume;

public:
    CCube();

    CCube(double len, double wid, double height);

    CCube(CCube & obj);

    double GetArea() override;

    double GetVolume() override;

    void Show() override;


};

#endif //LAB13_CCUBE_H
