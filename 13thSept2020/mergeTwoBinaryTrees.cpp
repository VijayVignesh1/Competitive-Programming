#include <algorithm>
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
        std::vector<int> Print(TreeNode* root, int level, std::vector<int> temp){
            if(root==NULL){
                temp.push_back(0);
                return temp;
            }
            else if(level==1){
                // cout<<root->val<<"\t";
                temp.push_back(root->val);
            }
            else{
                temp=Print(root->left,level-1,temp);
                temp=Print(root->right,level-1,temp);
                return temp;
            }
            return temp;
        }

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
//         void Print(TreeNode* t1, TreeNode* t2, TreeNode* t3){
//             if(t1==NULL and t2==NULL)
//                 return;
//             else{
//                 if(t1==NULL and t2!=NULL){
//                     // cout<<"t2 "<<t2->val<<" ";
//                     cout<<"t2:"<<t2->val<<" ";
//                     t3=new TreeNode(t2->val);
//                     if(t2->left!=NULL)
//                         Print(t1,t2->left,t3->left);
//                     if(t2->right!=NULL)
//                         Print(t1,t2->right,t3->right);
//                 }
//                 else if(t2==NULL and t1!=NULL){
//                     // cout<<"t1 "<<t1->val<<" ";
//                     cout<<"t1:"<<t1->val<<" ";
//                     // t3=new TreeNode(t1->val);
//                     Print(t1->left,t2,t3->left);
//                     if(t1->right!=NULL)
//                         Print(t1->right,t2,t3->right);
//                         // Print(t1->left,t2);
//                 }
//                 else{
//                     // if(t1==NULL)
//                     //     cout<<"t1 NULL";
//                     // if(t2==NULL)
//                     //     cout<<"t2 NULL";
                    
//                     // cout<<"t1 "<<t1->val<<" "<<"t2 "<<t2->val<<" ";
//                     cout<<"Add:"<<t1->val+t2->val<<" ";
//                     t3=new TreeNode(t1->val+t2->val);
//                     Print(t1->left,t2->left,t3->left);
//                     Print(t1->right,t2->right,t3->right);
//                 }
//                 return;
//             }
        // }
        TreeNode* merge(TreeNode* t, TreeNode* t3){
            if(t==NULL)
                return t3;
            else{
                if(t3==NULL)
                    t3->val=t->val;
                else
                    t3->val+=t->val;
                t3->left=merge(t->left,t3->left);
                t3->right=merge(t->right,t3->right);
                return t3;
            }
        }
        TreeNode* newNode(int data) 
        { 
            TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); 
            node->val = data; 
            node->left = node->right = NULL; 
            return (node); 
        } 
        TreeNode* insertLevelOrder(std::vector<int> arr, TreeNode* root,int i, int n){
            // Base case for recursion 
            if (i < n) 
            { 

                TreeNode* temp = newNode(arr.at(i));
                root = temp; 

                // insert left child 
                root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n); 

                // insert right child 
                root->right = insertLevelOrder(arr, 
                          root->right, 2 * i + 2, n); 
            } 
            return root; 
        }
        TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* t3;
        // t3=t1;
        // t3=merge(t1,t3);
        // cout<<t3;
        // Print(t1,t2,t3);
        int h_t1=height(t1);
        int h_t2=height(t2);
        // cout<<h_t1;
            std::vector<int> temp1,temp2;
        for(int i=0;i<=h_t1;i++){
            
            temp1=Print(t1,i,temp1);
            // cout<<temp;
           // for(int i=0; i < temp1.size(); i++)
           //      cout << temp1.at(i) << ' ';
        }
        // cout<<"\n";
        for(int i=0;i<=h_t2;i++){
            temp2=Print(t2,i,temp2);
            // cout<<temp;
           // for(int i=0; i < temp2.size(); i++)
           //      cout << temp2.at(i) << ' ';
        }
        // cout<<"\n";
        // count=0;
        while(true){
        if(temp1.size()==0)
            break;
        vector<int>::iterator it = temp1.begin();
        if(temp1.at(0)==0)
            temp1.erase(it);
        else
            break;
        }
  
        while(true){
        if(temp2.size()==0)
            break;
        vector<int>::iterator it = temp2.begin();
        if(temp2.at(0)==0)
            temp2.erase(it);
        else
            break;
        }

       for(int i=0; i < temp1.size(); i++)
            cout << temp1.at(i) << ' ';
        cout<<"\n";
       for(int i=0; i < temp2.size(); i++)
            cout << temp2.at(i) << ' ';
        // Print(t1,2);
        // cout<<temp1.size()<<" "<<temp2.size();
        // cout<<std::max(temp1.size(),temp2.size());
        std::vector<int> result;
        for(int i=0;i<=std::max(temp1.size(),temp2.size());i++){
            if(i<temp1.size() && i<temp2.size())
                result.push_back(temp1.at(i)+temp2.at(i));
            if(i<temp1.size() && i>=temp2.size())
                result.push_back(temp1.at(i));
            if(i>=temp1.size() && i<temp2.size())
                result.push_back(temp2.at(i));
        }
        cout<<"\n";
       for(int i=0; i < result.size(); i++)
            cout << result.at(i) << ' '; 
        t3=insertLevelOrder(result,t3,0,result.size());
        return t3;
        }
    
};
