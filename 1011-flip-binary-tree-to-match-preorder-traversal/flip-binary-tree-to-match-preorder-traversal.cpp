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
    bool dfs(TreeNode* root,vector<int>&ans,vector<int>&voyage,int &i){
        if(!root)return true;
        if(root->val!=voyage[i])return false;
        i++;
        if(root->left && i<voyage.size() && root->left->val!=voyage[i]){
            ans.push_back(root->val);
            swap(root->left,root->right);
        }
        return (dfs(root->left,ans,voyage,i) && (dfs(root->right,ans,voyage,i)));
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int n=voyage.size();
        vector<int>ans;
        int i=0;
        if(!dfs(root,ans,voyage,i))return {-1};
        return ans;
    }
};