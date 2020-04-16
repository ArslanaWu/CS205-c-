#include <iostream>

#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(double height,double width){
    this->height = height;
    this->width = width;
}
double Rectangle::getArea(){
    return width * width;
}
double Rectangle::getPerimeter()
{
    return 2 * width + 2 * height;
}
void Rectangle::display()
{
    cout << "Width: "     << width          << "\n"
         << "Height: "    << height         << "\n"
         << "Area: "      << getArea()      << "\n"
         << "Perimeter: " << getPerimeter() << endl;
}

int main(){
    Rectangle rec1 = *new Rectangle(4,40);
    cout << "Rectangle 1\n" << "-----------------------\n";
    rec1.display();

    Rectangle rec2 = *new Rectangle(3.5,35.9);
    cout << "Rectangle 2\n" << "-----------------------\n";
    rec2.display();

}