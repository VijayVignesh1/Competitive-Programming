#include <iostream>
#include<cmath>

using namespace std;


class Solution {
public:
    // If we add the number and its complement it should equal the 1111.. 
    // Example. Complement of 5(101) is 2(010). Add 5+2=7(111).
    // Subtract N with immediate pow(2,i)-1. 
    int bitwiseComplement(int N) {
        int i=0;   
        if(N==0)
            return 1;
        while(true){
            if(pow(2,i)-1>=N)
                return pow(2,i)-1-N;
            i+=1;
        }
        
    }   
};

int main()
{
    // Get input from the user and use the class method.
    Solution sol;
    int N;
    cout << "Print N:" << endl; 
    cin>>N;
    cout<<"The Complement of "<<N<<" is: "<<sol.bitwiseComplement(N);
    return 0;
}
