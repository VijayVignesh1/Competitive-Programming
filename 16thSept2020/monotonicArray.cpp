#include<cmath>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    // Find if the vector is monotonically increasing.
    // If not search for monotonically decreasing.
    // Else return false
    bool isMonotonic(std::vector<int>& A) {
        int max=-pow(2,31);
        int flag=0;
        for(int i=0;i<=A.size()-1;i++){
            if(A.at(i)>=max){
                max=A.at(i);
            }
            else{
                flag=1;
                break;
            }
        }
        if(flag==1){
        int min=pow(2,31)-1;
        for(int i=0;i<=A.size()-1;i++){
            if(A.at(i)<=min){
                min=A.at(i);
            }
            else{
                return false;
            }
        }
        }
        return true;
    }
};


int main()
{
  // Get the inputs from the user
  Solution sol;
  std::string line;
  int number;
  std::vector<int> arr;
  std::getline(std::cin, line);
  std::istringstream stream(line);
  while (stream >> number)
     arr.push_back(number);
  // Call class function and print the result
  cout<<sol.isMonotonic(arr);
  return 0;
}
