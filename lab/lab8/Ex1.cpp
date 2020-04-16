#include <iostream>

using namespace std;

struct CandyBar
{
    char brand[30];
    double weight;
    int calorie;
};

void set(CandyBar &cb)
{
    cout << "Enter brand name of a Candy Bar: ";
    cin.get();
    cin.get(cb.brand, 30);

    cout << "Enter weight of the candy bar: ";
    cin >> cb.weight;

    cout << "Enter calories (an integer value) in the candy bar: ";
    cin >> cb.calorie;
}

void set(CandyBar *const cb)
{
    cout << "Enter brand name of a Candy Bar: ";
    cin.get(cb->brand, 30);

    cout << "Enter weight of the candy bar: ";
    cin >> cb->weight;

    cout << "Enter calories (an integer value) in the candy bar: ";
    cin >> cb->calorie;
}

void show(const CandyBar & cb)
{
    cout << "Brand: " << cb.brand << "\n"
         << "Weight: " << cb.weight << "\n"
         << "Calories: " << cb.calorie << endl; 
}

void show(const CandyBar * cb)
{
    cout << "Brand: " << cb->brand << "\n"
         << "Weight: " << cb->weight << "\n"
         << "Calories: " << cb->calorie << endl;
}

int main()
{
    cout << "Call the set function of passing by pointer:\n";
    CandyBar cb1;
    CandyBar *ptr = &cb1;
    set(ptr);
    cout << "Call the show function of passing by pointer:\n";
    show(ptr);

    cout << "Call the set function of passing by reference:\n";
    CandyBar cb2;
    CandyBar & ref = cb2;
    set(ref);
    
    cout << "Call the show function of passing by reference:\n";
    show(ref);
}