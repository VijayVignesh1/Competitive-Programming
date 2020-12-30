#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<sstream>
using namespace std;


class Solution {
public:
    // loops through each element and adds the previous element to it
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        return nums;
    }
};

void print(vector<int> arr){
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
}
int main()
{
    // Get numRows from user and use the class function to get the result
	Solution sol;
	vector<int> arr;
	int number;
	string line;
	
	cout<<"Enter vector elements: \n";
	getline(cin,line);
	istringstream stream(line);
	
    while (stream >> number)
        arr.push_back(number);

	print(sol.runningSum(arr));
	return 0;
}
