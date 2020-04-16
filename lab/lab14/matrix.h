//
// Created by 泫泫 on 2019/12/12.
//

#ifndef LAB14_MATRIX_H
#define LAB14_MATRIX_H

const int MAXROWS = 2;
const int MAXCOLS = 3;

#include <iostream>

template <typename T>
class Matrix
{
private:
    T matrix[MAXROWS][MAXCOLS];
public:
    Matrix(){

    }

    void printMatrix(){
        for(int i = 0; i < MAXROWS; i++){
            for(int j = 0; j < MAXCOLS; j++){
                std::cout << matrix[i][j] << "   ";
            }
            std::cout << "\n";
        }
    }
    //柔性
    void setMatrix(T a[][MAXCOLS]){
        for(int i = 0; i < MAXROWS; i++){
            for(int j = 0; j < MAXCOLS; j++){
                matrix[i][j] = a[i][j];
            }
        }
    }

    void addMatrix(T a[][MAXCOLS]){
        for(int i = 0; i < MAXROWS; i++){
            for(int j = 0; j < MAXCOLS; j++){
                matrix[i][j] += a[i][j];
            }
        }
    }

};

#endif //LAB14_MATRIX_H
