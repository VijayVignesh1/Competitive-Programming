#include <iostream>
#include<sstream>
#include<vector>

using namespace std;

class Solution {
public:
    // iterate through the intervals and find if any interval in the list
    // is covered. If so break and don't include it in count
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int count=0;
        for(int i=0;i<intervals.size();i++){
            int flag=0;
            for(int j=0;j<intervals.size();j++){
                if(i==j)
                    continue;
                if(intervals[j][0]<=intervals[i][0] && intervals[i][1]<=intervals[j][1]){
                    flag=1;
                    break;
                }
            }
            if(!flag)
                count+=1;
        }
        return count;
    }
};

int main()
{
   Solution sol;
   int flag=0;
   vector<vector<int>> vec;
   cout<<"Enter the intervals line by line: \n";
   // Get the input matrix from the user line by line by using stream
   // apply the class function to the matrix and print the output
   while(true){
        int number;
        string line;
        std::vector<int> arr;
        std::getline(std::cin, line);
        std::istringstream stream(line);
        if(stream.str().empty())
            break;
        while (stream >> number)
            arr.push_back(number);
        vec.push_back(arr);
   }
   cout<<"Number of intervals after removing all the covered intervals: "<<sol.removeCoveredIntervals(vec);
   return 0;
}
