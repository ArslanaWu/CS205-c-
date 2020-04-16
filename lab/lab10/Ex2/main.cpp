#include "Ex2.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Please enter the number of a CandyBar:";
    int numbers;
    cin >> numbers;

    CandyBar *array = new CandyBar[numbers];

    for (int i = 0; i < numbers; i++)
    {
        cout << "CandyBar[" << i << "]\n";
        setCandyBar(array[i]);
    }

    for (int i = 0; i < numbers; i++)
    {
        cout << "CandyBar[" << i << "]\n";
        showCandyBar(array[i]);
    }

}