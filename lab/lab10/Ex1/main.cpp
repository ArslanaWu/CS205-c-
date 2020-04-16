#include <iostream>
#include "fun.h"

using namespace std;

int main(){
    double array[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

    double array1[5];
    double array2[5];
    double array3[5];

    CopyArray(array1,array);
    CopyArray(array2,array,5);
    CopyArray(array3,&array[0],&array[4]);

    PrintArray(array1,array2,array3,5);
    

}