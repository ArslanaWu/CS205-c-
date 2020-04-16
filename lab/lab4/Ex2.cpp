#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char word[] = {'d','o','n','e'};
    char *words = new char[10];
    int length = 0;
    cout << "Enter words (to stop, type the world done): \n";
    cin >> words;

    while(strcmp(word,words) != 0){
        length++;
        cin >> words;
    }

    cout << length;
    delete[] words;

}