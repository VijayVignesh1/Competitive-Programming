#include<iostream>
#include<cmath>
#include <sstream>
#include <vector>
using namespace std;
class Solution {
public:
    // if you find any zeros, make the first element of correponding row and column as 0
    // To identify the zero-ed rows and columns later.
    // Then traverse through first row and column and if the element is 0, make the
    // entire row and column as 0.
    void traverse(vector<vector<int>>& matrix, int w, int h){
        int flag=0;
        int flag2=0;
        for(int i=0;i<matrix[0].size();i++)
            if(matrix[0][i]==0)
                flag=1;
        for(int i=0;i<matrix.size();i++)
            if(matrix[i][0]==0)
                flag2=1;
        for(int h=0;h<matrix.size();h++){
            for(int w=0;w<matrix[h].size();w++)
                {   
                    if(matrix[h][w]==0){
                        matrix[h][0]=0;
                        matrix[0][w]=0;
                        }
                }
        }
        for(int h=1;h<matrix.size();h++){
            if(matrix[h][0]==0){
                for(int w=0;w<matrix[0].size();w++)
                    matrix[h][w]=0;
            }
        }
        for(int w=1;w<matrix[0].size();w++){
            if(matrix[0][w]==0){
                for(int h=1;h<matrix.size();h++)
                    matrix[h][w]=0;
            }
        }
        if(flag==1)
        {
            for(int w=0;w<matrix[0].size();w++)
                matrix[0][w]=0;
        }
        if(flag2==1)
            for(int h=0;h<matrix.size();h++)
                matrix[h][0]=0;            
    }
    void setZeroes(vector<vector<int>>& matrix) {
        traverse(matrix,0,0);
    }
};

//Prints Elements in the matrix
void printVector(vector<vector<int>>& matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++)
            cout<<matrix[i][j]<<" ";
        cout<<"\n";
    }
}
int main(){
    int m,n;
    Solution sol;
    vector<vector<int>> matrix;
    cout<<"Enter m,n\n";
    cin>>m>>n;
    // Get the matrix input and send it thourgh the class function
    for(int i=0;i<m;i++){
        std::vector<int> row;
        for(int j=0;j<n;j++){
            int temp;
            cout<<"Enter "<<i<<","<<j<<" value: \n";
            cin>>temp;
            row.push_back(temp);
        }
        matrix.push_back(row);
    }
    cout<<"Matrix before: \n";
    printVector(matrix);
    sol.setZeroes(matrix);
    cout<<"Matrix after: \n";
    printVector(matrix);
    return 0;
}
