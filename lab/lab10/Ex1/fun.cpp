#include "fun.h"
#include <iostream>

using namespace std;

void CopyArray(double (&target)[5], double (&source)[5])
{
    for (int i = 0; i < 5; i++)
    {
        target[i] = source[i];
    }
}

void CopyArray(double *target, double *source, int len)
{
    for (int i = 0; i < len; i++)
    {
        target[i] = source[i];
    }
}

void CopyArray(double *target, double *source_start, double *source_end)
{
    int i = 0;
    while (source_start != source_end)
    {
        target[i] = *source_start;
        source_start++;
        i++;
    }

    target[i++] = *(source_start++);
}

void PrintArray(double *target1, double *target2, double *target3, int len)
{
    for (int j = 0; j < 3; j++)
    {
        cout << "target" << j + 1 << "|      ";
    }
    cout << endl;

    for (int i = 0; i < len; i++)
    {
        cout << "    " << target1[i] << "|      "
             << "    " << target2[i] << "|      "
             << "    " << target3[i] << "|"
             << endl;
    }
}