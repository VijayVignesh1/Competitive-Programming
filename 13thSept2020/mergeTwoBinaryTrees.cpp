#include<iostream>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      //TreeNode() : val(0), left(nullptr), right(nullptr) {}
      //TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      //TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
        // Allocate memory for new node and create it
        TreeNode* newNode(int data) 
        { 
            TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); 
            node->val = data; 
            node->left = node->right = NULL; 
            return (node); 
        } 
    
        // Find the height of the given tree
        int height(TreeNode *root){
            if(root==NULL)
                return 0;
            else{
                int left_h=height(root->left);
                int right_h=height(root->right);
                if(left_h>right_h)
                    return left_h+1;
                else
                    return right_h+1;
                }
        }

        // Add the overlapping nodes in each level
        void Level_Add(TreeNode* root, TreeNode* root2, int level){
            if(root==NULL){
                if(root2!=NULL)
                return;
            }
            else if(level==1){
                if(root2!=NULL){
                    // cout<<root->val<<"+"<<root2->val<<" "; //uncomment to print added values
                    root->val+=root2->val;
                }
            }
            else{
                if(root->left!=NULL and root2->left!=NULL)
                Level_Add(root->left,root2->left,level-1);
                if(root->right!=NULL and root2->right!=NULL)
                Level_Add(root->right,root2->right,level-1);
                return;
            }
        }
    
        // Merge the non-overlapping nodes into a single tree
        void Level_Merge(TreeNode* root, TreeNode* root2, int level){
            if(root==NULL){
                if(root2!=NULL)
                return;
            }
            else if(level==1){
                if(root2!=NULL){
                if(root->left==NULL && root2->left!=NULL)
                    root->left=newNode(root2->left->val);
                if(root->right==NULL && root2->right!=NULL)
                    root->right=newNode(root2->right->val);
                }
            }
            else{
                if(root->left!=NULL and root2->left!=NULL)
                Level_Merge(root->left,root2->left,level-1);
                if(root->right!=NULL and root2->right!=NULL)
                Level_Merge(root->right,root2->right,level-1);
                return;
            }
        }
    
        // Final Merging function
        TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
            int h_t1=height(t1);
            int h_t2=height(t2);
            // Find height of each tree
            // Merge the short one with the tall one and
            // return the tall, merged tree
            if(h_t1>=h_t2){
                for(int i=1;i<=std::max(h_t1,h_t2);i++){
                    Level_Add(t1,t2,i);
                }
                for(int i=1;i<=std::max(h_t1,h_t2);i++){
                    Level_Merge(t1,t2,i);
                }
                return t1;
            }
            else{
                for(int i=1;i<=std::max(h_t1,h_t2);i++){
                    Level_Add(t2,t1,i);
                }
                for(int i=1;i<=std::max(h_t1,h_t2);i++){
                    Level_Merge(t2,t1,i);
                }
            return t2;
            }
    }
};

int height(TreeNode *root){
    if(root==NULL)
        return 0;
    else{
        int left_h=height(root->left);
        int right_h=height(root->right);
        if(left_h>right_h)
            return left_h+1;
        else
            return right_h+1;
        }
}
void printGivenLevel(TreeNode* root, int level)  
{  
    if (root == NULL)  
        return;  
    if (level == 1)  
        cout << root->val << " ";  
    else if (level > 1)  
    {  
        printGivenLevel(root->left, level-1);  
        printGivenLevel(root->right, level-1);  
    }  
}  

void printLevelOrder(TreeNode* root)  
{  
    int h = height(root);  
    int i;
    for (i = 1; i <= h; i++)  
        printGivenLevel(root, i);
}

int main(){
    Solution sol;
    //construct the two input trees
    TreeNode* root;
    root=sol.newNode(1);
    root->left=sol.newNode(3);
    root->left->left=sol.newNode(6);
    TreeNode* root2;
    root2=sol.newNode(1);
    TreeNode* result;
    // Merge the two trees and print the result
    result=sol.mergeTrees(root,root2);
    printLevelOrder(result);
    return 0;
}
