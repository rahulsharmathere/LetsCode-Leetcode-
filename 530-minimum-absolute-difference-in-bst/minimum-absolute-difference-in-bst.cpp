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
    void inorder(TreeNode*root,TreeNode*&prev,int &mini){
        if(!root)return ;
        inorder(root->left,prev,mini);
        if(prev){
            mini=min(mini,abs(prev->val-root->val));
        }
        prev=root;
        inorder(root->right,prev,mini);
    }
    int getMinimumDifference(TreeNode* root) {
        // minimum difference between any 2 nodes
        // it will be between 2 consecutive elements
        int mini=INT_MAX;
        TreeNode*prev=NULL;
        inorder(root,prev,mini);
        return mini;
    }
};