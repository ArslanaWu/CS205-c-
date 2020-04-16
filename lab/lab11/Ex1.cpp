#include <iostream>
#include <string>

#include "CandyBar.h"

using namespace std;

int CandyBar::setCandyBar()
{
    cout << "Enter brand name of a Candy Bar: ";
    cin.get(CandyBar::name, 30);

    cout << "Enter weight of the candy bar: ";
    cin >> CandyBar::weight;

    cout << "Enter calories (an integer value) in the candy bar: ";
    cin >> CandyBar::calorie;
}

void CandyBar::showCandyBar()
{
    cout << "Brand: " << CandyBar::name << "\n"
         << "Weight: " << CandyBar::weight << "\n"
         << "Calories: " << CandyBar::calorie << endl;
}

int main()
{
    CandyBar bar;

    bar.setCandyBar();
    bar.showCandyBar();
}