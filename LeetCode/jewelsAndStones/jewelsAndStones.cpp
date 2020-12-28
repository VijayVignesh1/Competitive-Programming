#include <iostream>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

class Solution {
public:
    // iterate through jewels and stones strings and find the number of overlapping
    // characters.
    int numJewelsInStones(string jewels, string stones) {
        int count=0;
        for(int i=0;i<jewels.size();i++)
            for(int j=0;j<stones.size();j++)
                if(jewels[i]==stones[j])
                    count+=1;
        return count;
    }
};

int main()
{
    // Get the two strings as input and apply class function on them and print the output.
    Solution sol;
    string jewels, stones;
    
    cout<<"Enter the jewels string: \n";
    getline(cin,jewels);

    cout<<"Enter the stones string: \n";
    getline(cin,stones);
    

    cout<<sol.numJewelsInStones(jewels, stones);
   
   return 0;
}
