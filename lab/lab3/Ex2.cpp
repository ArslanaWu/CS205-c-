#include <iostream>
using namespace std;

struct CandyBar{
    char name[20];
    double weight;
    int calories;
};

int main(){
    CandyBar bar1 = {
        "aaa aaa",
        1.1,
        111
    };
    CandyBar bar2 = {
        "bbb bbb",
        2.2,
        222
    };
    CandyBar bar3 = {
        "ccc ccc",
        3.3,
        333
    };
    
    CandyBar array[3] = {bar1,bar2,bar3};

    for(int i = 0;i < 3;i++){
        cout << "Brand: " << array[i].name 
    <<"\nWeight: " << array[i].weight 
    << "\nCalorie: " << array[i].calories
    << "\n";
    }

}