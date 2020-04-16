#include <iostream>

int main(){
    int first = 0;
    int second = 1;
    int sum = first + second;

    using namespace std;
    cout << "Enter a positive number: ";
    int max;
    cin >> max;

    cout << "Fibonacci Series: " << first << " " << second << " ";
    
    do{
        cout << sum << " ";

        first = second;
        second = sum;
        sum = first + second;
    }while(sum < max - 1);
}