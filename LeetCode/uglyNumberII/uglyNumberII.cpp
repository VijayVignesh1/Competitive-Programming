#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std; 

class Solution {
public:

    // Print the vector
    void print(vector<int> arr){
        for(int i=0;i<arr.size();i++)
            cout<<arr[i]<<" ";
    }
    
    // Find nth ugly number. Split the output into 3 parts.
    // one - multiply with 2, two - multiply with 3, three - multiply with 5
    // after every step multiply the previous number with 2,3 and 5.
    // Find min of three and assign it to next index if previous anc current number
    // are not the same. Then increment the respective i value (i2, i3 or i5).
    // Return the last number of the vector.
    int ugly_number(int n){
        vector<int> result;
        result.push_back(1);
        int i2=0,i3=0,i5=0,i=1,temp;
        vector<int>::iterator ip;
        if(n==1)
            return result[0];
        while(i!=n){
            temp=min(min(result[i2]*2,result[i3]*3),result[i5]*5);
            if(temp!=result[i-1]){
                result.push_back(temp);
                i+=1;
            }

            if(result[i2]*2==temp)
                i2+=1;
            else if(result[i3]*3==temp)
                i3+=1;
            else if(result[i5]*5==temp)
                i5+=1;
            
        }
        // To print the vector containing all n ugly numbers
        // uncomment below
        // print(result);
        return result[i-1];
    }
    
    int nthUglyNumber(int n) {
        int i;
        i=ugly_number(n);
        return i;
        }
        
};

int main()
{
    Solution sol;
    int n;
    cout<<"Enter n:";
    cin>>n;
    cout<<sol.nthUglyNumber(10);
    return 0;
}
