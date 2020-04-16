#include <iostream>
using namespace std;

int main(){
    const int max = 7;
    int row = 1;

    while(row <= max){
        int number = 1;
        while(number <= row){
            cout << number;
            number++;
        }
        while(number <= max){
            cout << "*";
            number++;
        }
        cout << "\n";
        row++;
    }
}