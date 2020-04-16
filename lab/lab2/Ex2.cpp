#include <iostream>
#include <stdbool.h>
#include <math.h>

using namespace std;
int main(){
    cout << "Range of char = " << -pow(2,sizeof(char)*8-1) << " to " << pow(2,sizeof(char)*8-1)-1;
    cout << "\nRange of unsigned char = " << 0 << " to " << pow(2,sizeof(unsigned char)*8)-1;
    cout << "\nRange of short = " << -pow(2,sizeof(short)*8-1) << " to " << pow(2,sizeof(short)*8-1)-1;
    cout << "\nRange of unsigned short = " << 0 << " to " << pow(2,sizeof(unsigned short)*8)-1;
    cout << "\nRange of int = " << -pow(2,sizeof(int)*8-1) << " to " << pow(2,sizeof(int)*8-1)-1;
    cout << "\nRange of unsigned int = " << 0 << " to " << pow(2,sizeof(unsigned int)*8)-1;
    cout << "\nRange of long = " << -pow(2,sizeof(long)*8-1) << " to " << pow(2,sizeof(long)*8-1)-1;
    cout << "\nRange of unsigned long = " << 0 << " to " << pow(2,sizeof(unsigned long)*8)-1;
    cout << "\nRange of long long = " << -pow(2,sizeof(long long)*8-1) << " to " << pow(2,sizeof(long long)*8-1)-1;
    cout << "\nRange of unsigned long long = " << 0 << " to " << pow(2,sizeof(unsigned long long)*8)-1;
    return 0;
}
