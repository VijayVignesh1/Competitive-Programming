#include <iostream>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

class Solution {
public:
    // takes in the array and a start and end index. Checks if the 
    // sorted array from index=start to index=end is same as the [start..end] array.
    // if so, returns 1. Else, returns 0.
    // Example, arr=[1,0,2,3,4], start=0, end=1; returns 1
    // arr=[2,3,1,0,4], start=0, end=1; return 0
    int sort_check(vector<int> arr, int start, int end){
        vector<int> check;
        for(int i=start;i<end;i++){
            check.push_back(arr[i]);
        }
        sort(check.begin(),check.end());
        int temp_check=start;
        for(int i=0;i<check.size();i++){
            if(temp_check!=check[i])
                return 0;
            temp_check+=1;
        }
        return 1;    
    }
    
    // If the sorted array from index to current index is same as the range from
    // index to current index, create a chunck and make index= current index.
    int maxChunksToSorted(vector<int>& arr) {
        int index=0, chunk=0;
        for(int i=0;i<arr.size();i++){
            if (sort_check(arr,index,i)){
                index=i;
                chunk+=1;
            }
        }
    return chunk;
    }
};

int main()
{
    // Get the vector as input and apply class function on them and print the output.
    Solution sol;
    vector<int> arr;
    string line;
    int number;
    
    cout<<"Enter the vector: \n";
    getline(cin,line);
    istringstream stream(line);
    while(stream>>number)
        arr.push_back(number);

    cout<<sol.maxChunksToSorted(arr);
   
   return 0;
}
