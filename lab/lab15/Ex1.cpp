#include <iostream>
#include <exception>

using namespace std;

class  OutOfRangeException : public exception {
public:
    int ii;
    int markk;

    OutOfRangeException(int i, int mark){
        ii = i;
        markk = mark;
    }

    const void what(int i, int mark) const throw() {
        cout << "The parameter" << i << " is "
        << mark << " which out of range(0-100)" << endl;
    }
};

double calculateAverage() {
    cout << "Please enter marks for 4 courses:";
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    try {
        if(a < 0 || a > 100){
            throw OutOfRangeException(1, a);
        }else if(b < 0 || b > 100){
            throw OutOfRangeException(2, b);
        }else if(c < 0 || c > 100){
            throw OutOfRangeException(3, c);
        }else if(d < 0 || d > 100){
            throw OutOfRangeException(4, d);
        }else{
            cout << "The average of the four courses is " << (double)(a + b + c + d) / 4;
        }
    }catch(OutOfRangeException &e){
        e.what(e.ii, e.markk);
    }
}

int main() {
    calculateAverage();
}

