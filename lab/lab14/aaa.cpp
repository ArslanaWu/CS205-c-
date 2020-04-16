//
// Created by 泫泫 on 2019/12/26.
//

#include <iostream>

class A{
public:
    int i;
    A():i(0){};
    int f(){
        return i;
    }
};

class B:
        public A{};

int main(){
    B b;
    int n = b.f();
    std::cout << n;
    return 0;
}