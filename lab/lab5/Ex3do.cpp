#include <iostream>

int main(){
    int first = 0;
    int second = 1; 

    using namespace std;
    cout << "Enter a positive number: ";
    int max;
    cin >> max;

    cout << "Fibonacci Series: " << first << " " << second << " ";
    
    for(int sum = first + second;sum < max;sum = first + second){
        cout << sum << " ";
        first = second;
        second = sum;
        
    }
}