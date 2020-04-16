//
// Created by 泫泫 on 2019/11/28.
//

#ifndef EXAMPLE_NUMBER_H
#define EXAMPLE_NUMBER_H

class Number{
    int number;

public:
    Number();
    Number(int num);

    int operator ++();//prefix
    int operator --();

    int operator ++(int);//postfix
    int operator --(int);


    friend std::ostream & operator<<(std::ostream& os,const Number& other);

};


#endif //EXAMPLE_NUMBER_H
