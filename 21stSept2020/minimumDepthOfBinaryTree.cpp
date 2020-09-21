/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
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
