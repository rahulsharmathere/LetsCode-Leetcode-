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
    void dfs(TreeNode* root,vector<int>&temp){
        if(!root)return ;
        dfs(root->left,temp);
        if(!root->left && !root->right)temp.push_back(root->val);
        dfs(root->right,temp);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>temp1;
        dfs(root1,temp1);
        vector<int>temp2;
        dfs(root2,temp2);
        if(temp1.size()!=temp2.size())return false;
        for(int i=0;i<temp1.size();i++){
            if(temp1[i]!=temp2[i])return false;
        }
        return true;

    }
};