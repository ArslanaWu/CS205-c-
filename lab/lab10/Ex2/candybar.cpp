#include "Ex2.h"
#include <iostream>
#include <string>

using namespace std;

int setCandyBar(CandyBar &snack)
{
    cin.get();
    cout << "Enter brand name of a Candy Bar: ";
    cin.get(snack.brand, 30);
    if (snack.brand[0] == ' ' || snack.brand[0] == '\0')
    {
        cout << "empty name detected!\n";
        exit(0);
    }

    cout << "Enter weight of the candy bar: ";
    cin >> snack.weight;

    cout << "Enter calories (an integer value) in the candy bar: ";
    cin >> snack.calorie;
}

void showCandyBar(const CandyBar &snack)
{
    cout << "Brand: " << snack.brand << "\n"
         << "Weight: " << snack.weight << "\n"
         << "Calories: " << snack.calorie << endl;
}