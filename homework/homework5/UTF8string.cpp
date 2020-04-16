#include <string>
#include <cstring>

#include "UTF8string.hpp"

using namespace std;

UTF8string::UTF8string(string utf8)
{
    this->utf8 = utf8;
}

std::ostream &operator<<(std::ostream &os, const UTF8string &other)
{
    os << other.utf8;
    return os;
}

string UTF8string::operator!()
{
    string invert;

    unsigned char *start = (unsigned char *)utf8.c_str();
    unsigned char *last = start;
    while (*last)
    {
        _utf8_incr(last);
    }
    unsigned char *pre = last;
    _utf8_decr(pre);

    while (last != start)
    {
        int size = last - pre;
        char a[size + 1];
        memcpy(a, pre, size + 1);
        a[size] = '\0';
        string b = a;
        invert += b;

        _utf8_decr(last);
        _utf8_decr(pre);
    }

    return invert;
    // string invert(utf8.rbegin(),utf8.rend());
    // return invert;
}

string UTF8string::operator+(const UTF8string &other)
{
    string add = utf8 + other.utf8;
    return add;
}

string UTF8string::operator*(int times)
{
    string multi;
    for (int i = 0; i < times; i++)
    {
        multi += utf8;
    }
    return multi;
}

string operator*(int times, const UTF8string &a)
{
    string multi;
    for (int i = 0; i < times; i++)
    {
        multi += a.utf8;
    }
    return multi;
}

void UTF8string::operator+=(const UTF8string &other)
{
    utf8 += other.utf8;
}

int UTF8string::length()
{
    return utf8_charlen((unsigned char *)utf8.c_str());
}

int UTF8string::bytes()
{
    return utf8.length();
}

int UTF8string::find(string substr)
{
    int pos = 0;
    unsigned char *p = utf8_search((unsigned char *)utf8.c_str(),
                                   (unsigned char *)substr.c_str());
    unsigned char *p_new = (unsigned char *)utf8.c_str();

    while (true)
    {
        if (*p == *p_new)
        {
            bool equal = true;
            unsigned char *p_copy = p;
            unsigned char *p_new_copy = p_new;

            for (int i = 0; i < substr.length(); i++)
            {
                p_copy++;
                p_new_copy++;

                if (*p_copy != *p_new_copy)
                {
                    equal = false;
                    break;
                }
            }

            if (equal)
            {
                break;
            }
            else
            {
                pos++;
                _utf8_incr(p_new);
            }
        }
        else
        {
            pos++;
            _utf8_incr(p_new);
        }
    }
    return pos;
}

void UTF8string::replace(string to_move, string replacement)
{
    int index = utf8.find(to_move);
    int len = to_move.length();
    while (index != string::npos)
    {
        utf8 = utf8.replace(index, len, replacement);
        index = utf8.find(to_move);
    }
}
