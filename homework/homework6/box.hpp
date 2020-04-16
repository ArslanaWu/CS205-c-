#ifndef BOX_HPP
#define BOX_HPP

#include <iostream>

class Box{
private:
    int l;
    int b;
    int h;
public:
    Box(){
        l = 0;
        b = 0;
        h = 0;
    }
    Box(int length, int breadth, int height){
        this -> l = length;
        this -> b = breadth;
        this -> h = height;
    }
    Box(const Box & b){
        l = b.l;
        this -> b = b.b;
        h = b.h;
    };

    int getLength(){
        return l;
    }
    int getBreadth(){
        return b;
    }
    int getHeight(){
        return h;
    }
    long long CalculateVolume(){
        return l * b * h;
    }

    bool operator<(const Box & other){
        bool smaller = false;

        if(l < other.l){
            smaller = true;
        }else if(b < other.b && l == other.l){
            smaller = true;
        }else if(h < other.h && b == other.b
                 && l == other.l ){
            smaller = true;
        }
        return smaller;
    }

    friend std::ostream & operator<<(std::ostream& os,const Box & other){
        os << other.l << " " << other.b << " " << other.h;
        return os;
    }
};

#endif