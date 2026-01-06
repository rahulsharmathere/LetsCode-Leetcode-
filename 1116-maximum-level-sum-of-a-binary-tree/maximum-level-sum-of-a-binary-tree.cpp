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
    void dfs(TreeNode* root,int level,map<int,int>&mp){
        if(root==NULL)return;
        mp[level]+=root->val;
        dfs(root->right,level+1,mp);
        dfs(root->left,level+1,mp);
    }
    int maxLevelSum(TreeNode* root) {
        if(root->right==NULL && root->left==NULL)return root->val;
        map<int,int>mp;//level,sum
        int level=1;
        dfs(root,level,mp);
        int ans=INT_MIN;
    
        for(auto it:mp){
            if(it.second>ans){
                ans=it.second;
                level=it.first;
            }
        }
        return level;
    }
};