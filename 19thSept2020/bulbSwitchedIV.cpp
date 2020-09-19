#include<iostream>
#include<sstream>
using namespace std;
class Solution {
public:
    // ignore all the zeros till we encounter the first 1 in the string.
    // start counting from there. Everytime the bit changes increase the count
    // answer is just the number of bit flips starting from the first 1.
    int minFlips(string target) {
        int flag=0,count=0;
        for(int i=0;i<target.size();i++){
            if(flag==0 && target[i]!='1')
                continue;
            else if(flag==0 && target[i]=='1'){
                count+=1;
                flag=1;
                continue;
            }
            if(flag==1 && target[i-1]!=target[i])
            {
                count+=1;
            }
        }
        return count;
    }
};

int main(){
    // Get string from user and use the class function to get the output
    Solution sol;
    string str;
    cout<<"Enter Strings of 0's and 1's: ";
    getline(cin,str);
    cout<<sol.minFlips(str);
    return 0;
}
