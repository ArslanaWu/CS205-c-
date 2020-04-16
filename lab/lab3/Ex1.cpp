#include <iostream>
using namespace std;

struct CandyBar{
    char name[20];
    double weight;
    int calories;
};

int main(){
    CandyBar bar1;
    cout << "Enter brand name of a Candy bar:";
    cin.getline(bar1.name,20);
    cout <<"Enter weight of the Candy bar:";
    cin >> bar1.weight;
    cout <<"Enter calories (an integer value) in the Candy bar:";
    cin >> bar1.calories;

    cout << "Brand: " << bar1.name 
    <<"\nWeight: " << bar1.weight 
    << "\nCalorie: " << bar1.calories;
}