#include <iostream>
#include <string>

using namespace std;

template <typename M_type>
M_type Max(M_type one, M_type two);

int main()
{
    int i_one = 3, i_two = 5;
    double j_one = 5.6, j_two = 7.3;
    string k_one = "donkey", k_two = "apple";

    cout << "The max of " << i_one << " and " << i_two << " is "
         << Max(i_one, i_two) << endl;
    cout << "The max of " << j_one << " and " << j_two << " is "
         << Max(j_one, j_two) << endl;
    cout << "The max of " << k_one << " and " << k_two << " is "
         << Max(k_one, k_two) << endl;

    return 0;
}

template <typename M_type>
M_type Max(M_type one, M_type two){
    M_type biggest;
    if (one < two){
        biggest = two;
    }else{
        biggest = one;
    }
    return biggest;
}