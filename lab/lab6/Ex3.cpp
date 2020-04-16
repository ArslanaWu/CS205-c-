#include <iostream>

using namespace std;

int main(){
    int quiz;
    int midterm;
    int final;
    char grade;

    cout << "Enter quiz score: \n";
    cin >> quiz;
    cout << "Enter midterm score: \n";
    cin >> midterm;
    cout << "Enter final score: \n";
    cin >> final;

    int average = (quiz + midterm + final)/3;

    if(average >= 90){
        grade = 'A';
    }else if(average >= 70 && average < 90){
        grade = 'B';
    }else if(average >= 50 && average < 70){
        grade = 'C';
    }else{
        grade = 'F';
    }

    cout << "Grade is " << grade;
}