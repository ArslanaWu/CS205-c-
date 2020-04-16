//
// Created by 泫泫 on 2019/9/26.
//

#include <iostream>
using namespace std;

struct CandyBar{
    char name[20];
    double weight;
    int calories;
};

int main(){
    int number;
    cout << "How many CandyBars? ";
    cin >> number;


    CandyBar *array = new CandyBar[number];

    for(int i = 0;i < number;i++){
        cout << "CandyBar #" << i <<": \n";
        cin.get();
        cout << "Please enter the brand: ";
        cin.getline(array[i].name,20);
        cout << "Please enter the weight: ";
        cin >> array[i].weight;
        cout << "Please enter the calories: ";
        cin >>array[i].calories;
    }

    cout << "Here is your collection: ";
    for(int i = 0;i < number;i++){
        cout << "\nBrand: " << array[i].name
        << "\nWeight: " << array[i].weight
        << "\nCalorie: " << array[i].calories;
    }


}