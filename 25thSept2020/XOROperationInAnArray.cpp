#include <iostream>
#include<cmath>

using namespace std;


class Solution {
public:
    // iterate through each number from start and xor with previous number
    int xorOperation(int n, int start) {
        int xor_result=start;
        int temp=start;
        int i=1;
        while(i!=n){
            temp=start+(2*i);
            xor_result^=temp;
            i+=1;
        }
        return xor_result;
    }
};


int main()
{
    // Get the inputs from the user and calculate the xors using 
    // class function
    Solution sol;
    int n,start;
    cout << "Enter n:";
    cin>>n;
    cout << "Enter start:";
    cin>>start;
    cout<<sol.xorOperation(n,start);
   
    return 0;
}
