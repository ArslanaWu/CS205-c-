#include <iostream>

using namespace std;

int main(){
    int entire = 0;
    int now;
    bool stop = false;
    while(!stop){
        cout << "Enter integer number: ";
        cin >> now;
        if(now == 0){
            cout << "The cumulative sum of the entire to date is: "<< entire << "\n";
            stop = true;
        }else{
            entire = now + entire;
            cout << "The cumulative sum of the entire to date is: " << entire << "\n";
        }

    }
}