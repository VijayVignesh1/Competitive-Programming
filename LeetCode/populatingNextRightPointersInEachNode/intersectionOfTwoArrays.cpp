#include <iostream>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

class Solution {
public:
    // Simple iteration through both the loops to find the common elements
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        vector<int>::iterator ip;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums2[j]==nums1[i]){
                    result.push_back(nums1[i]);
                    break;
                }
            }
        }
        sort(result.begin(), result.end());
        ip = std::unique(result.begin(), result.end());
        result.resize(std::distance(result.begin(), ip));
        return result;
    }
};

// Print the entire matrix
void print(vector<int> arr){
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    // Get the two vectors from user and apply class function to them
    Solution sol;
    vector<int> nums1,nums2,result;
    string line;
    int number;
    cout<<"Enter the two vectors: \n";
   
    getline(cin,line);
    istringstream stream(line);
    while(stream>>number)
        nums1.push_back(number);

    getline(cin,line);
    istringstream stream1(line);
    while(stream1>>number)
        nums2.push_back(number);
    
    // Calculate and print result
    result=sol.intersection(nums1,nums2);
    print(result);
    return 0;
}
