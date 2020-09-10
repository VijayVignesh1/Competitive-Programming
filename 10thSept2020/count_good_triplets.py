#include <iostream>
#include<cmath>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count=0;
        for(int i=0;i<arr.size()-2;i++){
            for(int j=i+1;j<arr.size()-1;j++){
                for(int k=j+1;k<arr.size();k++){
                    if(abs(arr[i]-arr[j])<=a && abs(arr[j]-arr[k])<=b && abs(arr[i]-arr[k])<=c)
                        count+=1;
                }
            }
        }
        return count;
    }
};

int main()
{
  // Get the inputs from the user
  int a,b,c;
  int result;
  Solution s;
  std::string line;
  int number;
  std::vector<int> arr;
  std::getline(std::cin, line);
  std::istringstream stream(line);
  while (stream >> number)
     arr.push_back(number);
     write_vector(arr);

  // Call class function and print the result
  result=s.countGoodTriplets(arr,a,b,c);
  cout<<result;
  return 0;
}
