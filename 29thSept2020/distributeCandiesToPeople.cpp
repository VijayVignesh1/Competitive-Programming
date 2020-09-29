#include <iostream>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

class Solution {
public:
    // Initialize all elements to 0. Loop and distribute candies to 
    // each element of matrix accordingly
    vector<int> distributeCandies(int candies, int num_people) {
        int count=1,j=0;
        vector<int> result;
        for(int i=0;i<num_people;i++)
            result.push_back(0);
        while(candies>count){
            result[j]+=count;
            candies-=count;
            if(j==result.size()-1)
                j=0;
            else
                j+=1;
            count+=1;
        }
        result[j]+=candies;
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
    // Get the number of candies and people from user and apply class function to them
    Solution sol;
    vector<int> result;
    int candies,num_people;
    cout<<"Enter the number of Candies: \n";
    cin>>candies;

    cout<<"Enter the number of People: \n";
    cin>>num_people;

    // Calculate and print result
    result=sol.distributeCandies(candies,num_people);
    print(result);
    return 0;
}
