#include <iostream>
#include "CStereoShape.h"
#include "CCube.h"
#include "CSphere.h"

using namespace std;

int main() {
    CCube * a_cube = new CCube(4.0,5.0,6.0);
    CSphere * c_sphere = new CSphere(7.9);

    CStereoShape * p = a_cube;
    p -> Show();

    p = c_sphere;
    p -> Show();

    cout << CStereoShape::GetNumOfObject();

    delete a_cube;
    delete c_sphere;
}