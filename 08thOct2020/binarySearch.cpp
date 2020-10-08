#include <iostream>
#include<vector>
#include<sstream>

using namespace std;

class Solution {
public:
    // searches the sorted list by looking at the middle element of the list
    // if equal return index, else depending on the middle element and target
    // search the lower or thr upper part of the list from midddle element
    int binary_search(vector<int>& nums, int i, int j, int target){
        
        if(nums[int((i+j)/2)]==target)
            return (i+j)/2;
        
        if(i==j && nums[i]!=target)
            return -1;
        
        if (i+1==j && nums[i]!=target && nums[j]!=target)
            return -1;
        
        else{
            int result;
            if(nums[int((i+j)/2)]>target)
                result = binary_search(nums, i, int((i+j)/2)-1,target);
            else
                result = binary_search(nums, int((i+j)/2)+1,j,target);
            return result;
        }
    }
    int search(vector<int>& nums, int target) {
        return binary_search(nums,0,nums.size()-1,target);
    }
};

// prints the given vector
void print_vector(vector<int> &arr){
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

int main()
{
    // Get the input from the user and apply class function to it
    Solution sol;
    int number;
    string line;
    vector<int> arr;
    int target;
    
    cout<<"Enter the vector to be searched: \n";
    getline(cin,line);
    istringstream stream(line);
    while(stream>>number)
        arr.push_back(number);
    print_vector(arr);
    
    cout<<"Enter number to be searched: \n";
    cin>>target;
    
    cout<<sol.search(arr,target);
    return 0;
}
