#include <iostream>
#include <String>

using namespace std;

int main(){
    char firstLetter;
    string input;
    int vowel = 0;
    int consonants = 0;
    int others = 0;

    cout << "Enter words (q to quit): \n";
    cin >> input;

    //cout << 'a'||'b'||'c';

    while(input != "q"){
        if(isalpha(input.at(0))){
            if(input.at(0) == 'a'|| input.at(0) == 'e' ||input.at(0) == 'i'||input.at(0) == 'o'||input.at(0) == 'u'||
            input.at(0) == 'A' ||input.at(0) == 'E' || input.at(0) == 'I'||input.at(0) == 'O'||input.at(0) == 'U'){
                vowel++;
            }else{
                consonants++;
            }
        }else{
            others++;
        }
        cin >> input;
    }

    cout << vowel << " words begining with vowels\n";
    cout << consonants << " words begining with consonants\n";
    cout << others << " others\n";


}