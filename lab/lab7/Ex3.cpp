#include <iostream>
#include <string>
#include<cstdlib>

using namespace std;

int Fill_array(double arr[],int size)
{
    int amount = 0;

    for(int i = 0;i < size;i++){
        cout << "Enter the value #" << i << ": ";

        string str1;
        getline(cin,str1);
        
        if(!isalpha(str1[0])){
            arr[i] = std::stoi(str1);
            amount++;
        }else{
            return amount;
        }
    }
    return amount;
}

void Show_array(double *arr,int size)
{
    cout << "The output is as follows: \n";

    for(int i = 0;i < size;i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void Reverse_array(double *arr,int size)
{
    if(size - 1 >= 0){
        cout << arr[size - 1] << " ";
        size--;
        if(size == 0){
            cout << "\n";
        }
        Reverse_array(arr,size);
    }
}

void Reverse_array_part(double *arr,int size)
{
    if(size - 1 >= 1){
        cout << arr[size - 1] << " ";
        size--;
        Reverse_array_part(arr,size);
    }
}

int main()
{
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;
    cin.get();

    double arr[size];

    int true_size = Fill_array(arr,size);
    
    Show_array(arr,true_size);
    
    Reverse_array(arr,true_size);

    cout << arr[0] << " ";
    Reverse_array_part(arr,true_size - 1);
    cout << arr[true_size - 1] << " ";

    //cout << *(arr-1) << " ";
    
}