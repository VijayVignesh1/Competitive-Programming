#include <iostream>
#include<vector>
#include<cmath>
#include<sstream>

using namespace std;


class Solution {
public:
    // corrects the jumbled string based on the given indices vector
    string restoreString(string s, vector<int>& indices) {
        string result;
        result=s;
        //if s.size()-1 doesn't give the right answer, change to i<s.size()
        // got different results in different compiler
        // leetcode answer was i<s.size()
        for(int i=0;i<s.size()-1;i++){
            result[indices[i]]=s[i];
        }
        return result;
    }
};


int main()
{
   // get input from the user
   Solution sol;
   std::string s;
   std::vector<int> indices;
   int number;
   std::string line;
   cout<<"Enter jumbled string: \n";
   getline(cin,s);
   cout<<"Enter ordered indices: \n";
   std::getline(std::cin,line);
   std::istringstream stream(line);
   while(stream >> number)
        indices.push_back(number);
    // call the class function and print the output
    cout<<indices[4];
    cout<<sol.restoreString(s,indices);
   
   return 0;
}
