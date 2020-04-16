#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

const int LENGTH = 35;
const int SIZE = 1000;

struct City
{
    string city_name;
    string country_name;
    double latitude;
    double longitude;
};

City *cities = new City[SIZE];

void Create_struct(int i, string &line)
{
    int position[4];
    int amount = 0;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            position[amount] = i;
            amount++;
        }
    }
    //find position of ","

    string city_name = line.substr(0, position[0]);
    if (city_name.length() > LENGTH)
    {
        cout << "Name of " << city_name << " is too long, only store part\n";
        cities[i].city_name = city_name.substr(0, LENGTH);
    }
    else
    {
        cities[i].city_name = city_name;
    }
    line.erase(0, position[1] + 1);
    //city name

    string country_name = line.substr(0, position[2] - position[1] - 1);
    if (country_name.length() > LENGTH)
    {
        cout << "Name of " << country_name << " is too long, only store part\n";
        cities[i].country_name = country_name.substr(0, LENGTH);
    }
    else
    {
        if(country_name.empty()){
            cout << "Country name of city " << city_name << " is empty\n";
        }
        cities[i].country_name = country_name;
    }
    line.erase(0, position[2] - position[1]);
    //country name

    stringstream ss;
    ss << line.substr(0, position[3] - position[2] - 1);
    ss >> cities[i].latitude;
    line.erase(0, position[3] - position[2]);

    stringstream sss;
    sss << line;
    sss >> cities[i].longitude;
}

void Edit_string(string &name)
{
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    name.erase(0, name.find_first_not_of(" "));
    name.erase(name.find_last_not_of(" ") + 1);
}

int Search(string &name)
{
    vector<int> found;

    while (found.empty())
    {
        for (int i = 0; i < SIZE; i++)
        {
            string city_name = cities[i].city_name;
            Edit_string(city_name);
            string::size_type idx = city_name.find(name);

            if (idx != string::npos)
            {
                found.push_back(i);
            }
        }
        if (found.empty())
        {
            cout << "Can not find that city, please input again: ";
            getline(cin, name);
            while (name.length() < 3)
            {
                cout << "Please input longer: ";
                getline(cin, name);
                Edit_string(name);
            }
            Edit_string(name);
        }
    }

    if (found.size() > 1)
    {
        cout << "There are more than one match your input:\n";
        for (int i = 0; i < found.size(); i++)
        {
            cout << i << "." << cities[found[i]].city_name << "   "
                             << cities[found[i]].country_name << "\n";
        }
        cout << "Please choose the one you want, input its number: ";
        int want;
        cin >> want;
        cin.get();
        return found[want];
    }
    else if (found.size() == 1)
    {
        return found[0];
    }
}

void calculate(int city1, int city2)
{
    double phi1 = (90 - cities[city1].latitude) * 3.1415 / 180;
    double phi2 = (90 - cities[city2].latitude) * 3.1415 / 180;

    double c = sin(phi1) * sin(phi2) * cos((cities[city1].longitude - cities[city2].longitude) * 3.1415 / 180) + cos(phi1) * cos(phi2);
    double distance = 6371 * acos(c);

    cout << "The distance between " << cities[city1].city_name << " and " << cities[city2].city_name << " is " << distance << " km\n";
}

int main()
{
    ifstream inFile;
    inFile.open("world_cities.csv");
    if (!inFile.is_open())
    {
        cout << "Could not open the file, program terminate.\n";
        exit(EXIT_FAILURE);
    }

    int time = 0;
    for (int i = 0; i < SIZE; i++)
    {
        string line;
        getline(inFile, line);
        if(line.empty()){
            break;
        }
        Create_struct(i, line);
    }
    //fill array

    cout << "Input name of first city: ";
    string name1;
    getline(cin, name1);
    Edit_string(name1);

    //maior loop
    while (name1 != "bye")
    {
        while (name1.length() < 3)
        {
            cout << "Please input longer: ";
            getline(cin, name1);
            Edit_string(name1);
        }
        int city1 = Search(name1);
        //name and position in array of the first city

        cout << "Input name of second city: ";
        string name2;
        getline(cin, name2);
        Edit_string(name2);

        while (name2.length() < 3)
        {
            cout << "Please input longer: ";
            getline(cin, name2);
            Edit_string(name2);
        }
        int city2 = Search(name2);
        //name and position in array of the second city

        calculate(city1, city2);
        //calculate distance

        cout << "Input name of first city: ";
        getline(cin, name1);
        Edit_string(name1);
        //read name of first city again
    }

    inFile.close();

    delete[] cities;
}
