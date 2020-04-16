#include <iostream>

using namespace std;

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void Value_Struct(box box1){
    cout << "Before Setting Volume:"
         << "\nMaker: " << box1.maker
         << "\nHeight: " << box1.height
         << "\nWidth: " << box1.width
         << "\nLength: " << box1.length
         << "\nVolume: " << box1.volume;
}

void Reference_Struct(box* box1){
    box1 -> volume = box1 -> height * box1 -> width * box1 -> length;
}

int main(){
    box box1 = {"Jinan University",3.4, 4.5, 5.6, 0};

    Value_Struct(box1);

    Reference_Struct(&box1);

    cout << "\nAfter Setting Volume:"
         << "\nMaker: " << box1.maker
         << "\nHeight: " << box1.height
         << "\nWidth: " << box1.width
         << "\nLength: " << box1.length
         << "\nVolume: " << box1.volume;

}
