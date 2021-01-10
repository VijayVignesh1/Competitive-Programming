#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;


class Solution {
public:
    // generates each row one by one by adding the n-1th elemenet of previous row
    // and nth element of previous row to get the nth element of current row
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> temp;
        // if numRows=0 or 1 or 2, directly return
        if(numRows==0)
            return result;
        temp.push_back(1);
        result.push_back(temp);
        if(numRows==1)
            return result;        
        temp.push_back(1);
        result.push_back(temp);
        if(numRows==2)
            return result;
        // if numRows>2 calculate element by element value of each row
        // and return matrix 
        for(int i=2;i<numRows;i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=1;j<i;j++)
                temp.push_back(result[i-1][j-1]+result[i-1][j]);
            temp.push_back(1);
            
            result.push_back(temp);
        }
        return result;
    }
};

// Prints the matrix line by line
void print_matrix(vector<vector<int>> result){
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    // Get numRows from user and use the class function to get the result
	Solution sol;
	vector<vector<int>> result;
	int numRows;
	cout<<"Enter number of rows to print: \n";
	cin>>numRows;
	result = sol.generate(numRows);
	print_matrix(result);
	return 0;
}
