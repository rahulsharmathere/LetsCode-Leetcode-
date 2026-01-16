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
    bool helper(TreeNode* root,int targetSum){
        targetSum-=root->val;
        if(!root->left && !root->right)return(targetSum==0);
        bool b1=false;
        if(root->left)b1=helper(root->left,targetSum);
        if(b1)return true;
        bool b2=false;
        if(root->right)b2=helper(root->right,targetSum);
        if(b2)return true;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return false;
        if(!root->right && !root->left)return(root->val==targetSum);
        bool ans=helper(root,targetSum);
        return ans;
    }
};