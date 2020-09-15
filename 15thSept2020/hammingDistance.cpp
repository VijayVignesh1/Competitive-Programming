#include<cmath>
#include<iostream>

using namespace std;

class Solution {
public:
    // Finds the power of 2 which is nearest to the given number
    int findNearestPower(int num){
        int power=0;
        while(true){
            if(num/pow(2,power)<1.0)
                return power-1;
            if(num/pow(2,power)==1.0)
                return power;
            power+=1;
        }
    }
    
    // Finds the number of 1's in the binary representation of the given number
    int numberOfOnes(int num){
        int count=0;
        if(num%2!=0){
            count+=1;
            num-=1;
        }
        int powers;
        while(num!=0){
            powers=findNearestPower(num);
            num-=pow(2,powers);
            count+=1;
        }
        return count;
    }
    
    // Hammining distance is just the number of ones in the binary representation
    // of the xor of the two given numbers
    int hammingDistance(int x, int y) {
        return numberOfOnes(x^y);
    }
};

int main(){
    // Get the input and apply hammingDistance class function
    Solution sol;
    int num_1,num_2, result;
    cout<<"Enter first number: \n";
    cin>>num_1;
    cout<<"Enter second number: \n";
    cin>>num_2;
    result=sol.hammingDistance(num_1,num_2);
    cout<<"The Hamming distance between the two numbers is: \t"<<result;
}
