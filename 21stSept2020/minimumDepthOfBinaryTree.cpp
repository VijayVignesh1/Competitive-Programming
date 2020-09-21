#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    // Finds depth using recursion
    // Find depth of left and right subtree and return the one with the
    // minimum depth.
    int depth(TreeNode* root, int tree_depth){
        if(root==NULL)
            return tree_depth;
        else{
            int depth_left=depth(root->left,tree_depth+1);
            int depth_right=depth(root->right,tree_depth+1);
            if(depth_left<=depth_right)
                return depth_left;
            else
                return depth_right;
        }
        }
    int minDepth(TreeNode* root) {
        int result=depth(root,0);
        return result;
    }
};

// Allocates memory for each node of the tree
TreeNode* newNode(int data) 
{ 
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); 
    node->val = data; 
    node->left = node->right = NULL; 
    return (node); 
} 

int main(){
    Solution sol;
    int result;
    //construct the Binary Tree
    TreeNode* root;
    root=newNode(1);
    root->left=newNode(3);
    root->left->left=newNode(6);
    // Find the minimum depth using the class function and print result
    result=sol.minDepth(root);
    cout<<result;
    return 0;
}
