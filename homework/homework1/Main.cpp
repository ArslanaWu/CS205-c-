#include <iostream>
#include <math.h>
#include <string>
using namespace std;

struct City{
    string name;
    double latitude;
    double longitude;
};

int main(){
    City city1;
    City city2;
    int time = 0;

    cout << "The first city: ";
    getline(cin,city1.name);
    while(city1.name.length() > 30){
        cout << "input is too long, please less than 30 characters and input again";
        cin >> city1.name;
    }
    city1.name.erase(0,city1.name.find_first_not_of(" "));
    city1.name.erase(city1.name.find_last_not_of(" ") + 1);
    while(city1.name.empty()){
        cout << "input is invalid, please input again\n";
        cin >> city1.name;
        city1.name.erase(0,city1.name.find_first_not_of(" "));
        city1.name.erase(city1.name.find_last_not_of(" ") + 1);
    }

    cout << "The latitude and longitude of first city: ";
    cin >> city1.latitude >> city1.longitude;
   
    while(!cin || (city1.latitude > 90 || city1.latitude < -90)
           ||(city1.longitude > 180 || city1.longitude < 0)){
        cin.clear();
        cin.get();
        cin.sync();
        cout << "input is invalid, please input again\n";
        cin >> city1.latitude >>city1.longitude;
    }
    
    cin.get();

    cout << "The second city: ";
    getline(cin,city2.name);     
    while(city2.name.length() > 30){
        cout << "input is too long, please less than 30 characters and input again";
        cin >> city2.name;
    }
    city2.name.erase(0,city2.name.find_first_not_of(" "));
    city2.name.erase(city2.name.find_last_not_of(" ") + 1);
    while(city2.name.empty()){
        cout << "input is invalid, please input again\n";
        cin >> city2.name;
        city2.name.erase(0,city2.name.find_first_not_of(" "));
        city2.name.erase(city2.name.find_last_not_of(" ") + 1);
    }

    cout << "The latitude and longitude of second city: ";
    cin >> city2.latitude >> city2.longitude;
    while(!cin || city2.latitude > 90 || city2.latitude < 0
            || city2.longitude > 180 || city2.longitude < 0){
        cin.clear();
        cin.get();
        cin.sync();
        cout << "input is invalid, please input again\n";
        cin >> city2.latitude >>city2.longitude;
    }

    
    double phi1 = (90 - city1.latitude)*3.1415/180;
    double phi2 = (90 - city2.latitude)*3.1415/180;

    double c = sin(phi1)*sin(phi2)
    *cos((city1.longitude-city2.longitude)*3.1415/180)
    +cos(phi1)*cos(phi2);
    double distance = 6371*acos(c);
    
    cout << "The distance between "<< city1.name << " and " << city2.name << " is " << distance << " km";
}