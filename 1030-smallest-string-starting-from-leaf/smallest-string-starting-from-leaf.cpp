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
    void helper(TreeNode* root,string s,vector<string>&ans){
        char c=root->val + 'a';
        s+=c;
        if(!root->right && !root->left){
            reverse(s.begin(),s.end());
            ans.push_back(s);
            return;
        }
        if(root->left)helper(root->left,s,ans);
        if(root->right)helper(root->right,s,ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string>ans;
        string s="";
        helper(root,s,ans);
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};