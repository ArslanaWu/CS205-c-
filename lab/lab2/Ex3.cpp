#include <iostream>

using namespace std;

int main(){
    int seconds;
    cout << "Enter the number of seconds:";
    cin >> seconds;
    
    int days = seconds/60/60/24;
    int hours = (seconds-days*24*60*60)/60/60;
    int minutes = (seconds-days*24*60*60-hours*60*60)/60;

    cout << seconds << " seconds = " << days << " days, " << hours << " hours, " << 
    minutes << " minutes, " << seconds%60 << " seconds";
    
    return 0;
}