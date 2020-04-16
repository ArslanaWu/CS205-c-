#include <iostream>
#include <string>
#include <cstring>
#include "utf8.h"

using namespace std;

class UTF8string
{
private:
    string utf8;

public:
    UTF8string(string utf8);

    friend std::ostream &operator<<(std::ostream &os, const UTF8string &other);

    string operator!();

    string operator+(const UTF8string &other);

    string operator*(int times);

    friend string operator*(int times, const UTF8string &a);

    void operator+=(const UTF8string &other);

    int length();

    int bytes();

    int find(string substr);

    void replace(string to_move, string replacement);
};