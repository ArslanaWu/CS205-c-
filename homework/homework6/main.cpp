#include <iostream>
#include "box.hpp"

using namespace std;

int main() {
    Box a = Box();
    Box b = Box(1,1,1);
    Box c = Box(b);
    Box d = Box(1,2,2);
    Box e = Box(1,2,3);

    cout << a.getLength() << " "
         << a.getBreadth() << " "
         << a.getHeight() << "\n"

         << b.getLength() << " "
         << b.getBreadth() << " "
         << b.getHeight() << "\n"

         << b.CalculateVolume() << "\n";

    cout << c << "\n";

    cout << (a < b) << " "
         << (b < c) << " "
         << (c < d) << " "
         << (d < e) << "\n";


    cout << e;






}