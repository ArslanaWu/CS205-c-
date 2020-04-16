#include <iostream>

using namespace std;

template <typename T>
T max5(T array[])
{
    T max = array[0];
    for(int i = 1;i < 5;i++){
        if(max < array[i])
        {
            max = array[i];
        }
    }
    return max;
}

int main()
{
    int arr1[5] = {1,2,3,4,5};
    double arr2[5] = {1.1,2.0,3.0,4.0,5.5};

    cout << "max int: " << max5<int>(arr1);
    cout << "\nmax double: " << max5<double>(arr2);
}