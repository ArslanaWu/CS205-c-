//
// Created by 泫泫 on 2019/12/11.
//

#ifndef LAB13_CSTEREOSHAPE_H
#define LAB13_CSTEREOSHAPE_H

class CStereoShape{
private:

public:
    static int numberOfObject;

    CStereoShape();

    virtual double GetArea();

    virtual double GetVolume();

    virtual void Show();

    static int GetNumOfObject();
};

#endif //LAB13_CSTEREOSHAPE_H
