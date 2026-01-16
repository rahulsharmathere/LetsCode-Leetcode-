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
    void help(TreeNode* root,vector<vector<int>>&ans,vector<int>temp,int targetSum){
        temp.push_back(root->val);
        targetSum-=root->val;
        if(!root->right && !root->left){
            if(targetSum==0) ans.push_back(temp);
            return ;
        }
        if(root->right)help(root->right,ans,temp,targetSum);
        if(root->left)help(root->left,ans,temp,targetSum);

    }
    vector<vector<int>> pathSum(TreeNode* root,int targetSum) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        vector<int>temp;
        help(root,ans,temp,targetSum);
        return ans;
    }
};