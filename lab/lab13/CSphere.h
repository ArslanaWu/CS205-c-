//
// Created by 泫泫 on 2019/12/11.
//

#ifndef LAB13_CSPHERE_H
#define LAB13_CSPHERE_H

#include "CStereoShape.h"

class CSphere : public CStereoShape{
private:
    double radius;
    double area;
    double volume;

public:
    CSphere();

    CSphere(double radius);

    CSphere(CSphere & obj);

    double GetArea() override;

    double GetVolume() override;

    void Show() override;



};

#endif //LAB13_CSPHERE_H
