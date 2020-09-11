#include<iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        \\ The solution can be obtained by just subtracting the number with the nearest multiple of 9.
        \\ E.g. 55-->10-->1 can be obtained in O(1) by 55-(9*6)=1
        if(num-9*(num/9)==0 && num!=0)
            return 9;
        return num-9*(num/9);
    }
};

int main(){
    int num, result;
    Solution s;
    cin>>num;
    result=s.addDigits(num);
    cout<<result;
    return 0;
}
