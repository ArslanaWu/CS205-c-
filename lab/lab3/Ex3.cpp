#include <iostream>
using namespace std;

struct PizzaAnalysis{
    char name[20];
    double diameter;
    double weight;
};

int main(){
    int number;
    cout << "Enter number of pizza: ";
    cin >> number;
    PizzaAnalysis *ptr = new PizzaAnalysis[number];
    for(int i = 0;i < number;i++){
        cout << "Enter name of pizza: ";
        cin.get();
        cin.getline(ptr[i].name,20);
        
        //cin >> ptr[i].name;
        cout << "Enter diameter of pizza: ";
        cin >> ptr[i].diameter;
        cout << "Enter weight of pizza: ";
        cin >>ptr[i].weight;

        cout << ptr[i].name << " "
        << ptr[i].diameter << " "
        << ptr[i].weight;
    }
}