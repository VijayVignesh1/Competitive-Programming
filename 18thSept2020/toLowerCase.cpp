#include<iostream>
#include<sstream>
using namespace std;
class Solution {
public:
    // Add 32 to the ascii value of the upper case characters
    string toLowerCase(string str) {
        for(int i=0;i<str.size();i++){
            int temp;
            temp=str[i];
            if(temp>=65 && temp<90){
                temp+=32;
                str[i]=temp;
            }
        }
         return str; 
    }
};

int main(){
    // Get string from user and use the class function to get the output
    Solution sol;
    string str;
    cout<<"Enter String";
    getline(cin,str);
    cout<<sol.toLowerCase(str);
}
