#include <iostream>
#include <algorithm>

#define MAX1 2000000 //limit of amount

struct Num{
    int index;
    int value;

    bool operator< (const Num& num) const{
        return value < num.value;
    }
};

int n;
Num nums[MAX1];
int rank_index[MAX1], pre_index[MAX1],
    next_index[MAX1], nums_copy[MAX1];

void complete_info(){
    for(int i = 0; i < n; ++i){
        rank_index[i] = nums[i].index;
    }

    for(int i = 0; i < n; ++i){
        if(i == 0){
            pre_index[rank_index[i]] = n;
        }else{
            pre_index[rank_index[i]] = rank_index[i - 1];
        }

        if(i == n - 1){
            next_index[rank_index[i]] = n;
        }else{
            next_index[rank_index[i]] = rank_index[i + 1];
        }
    }
}

long long calculate(){
    long long result = 0;

    int curr = n - 1, pre, next;
    int num = nums_copy[curr];

    while(curr > 0){
        if(pre_index[curr] == n){
            next = nums_copy[next_index[curr]];
            result += abs(next - num);

            pre_index[next_index[curr]] = pre_index[curr];
        }
        else if(next_index[curr] == n){
            pre = nums_copy[pre_index[curr]];
            result += abs(pre - num);

            next_index[pre_index[curr]] = next_index[curr];
        }
        else{
            pre = nums_copy[pre_index[curr]];
            next = nums_copy[next_index[curr]];

            result += std::min(abs(next - num), abs(pre - num));

            next_index[pre_index[curr]] = next_index[curr];
            pre_index[next_index[curr]] = pre_index[curr];
        }

        curr--;
        num = nums_copy[curr];
    }

    return result + nums_copy[0];
}

int main(){
    using namespace std;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> nums[i].value;
        nums[i].index = i;
        nums_copy[i] = nums[i].value;
    }

    sort(nums, nums + n);

    complete_info();

    cout << calculate();
}


