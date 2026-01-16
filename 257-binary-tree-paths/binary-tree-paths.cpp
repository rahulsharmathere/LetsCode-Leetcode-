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
    void help(TreeNode* root,vector<string>&ans,string s){
        string str=to_string(root->val);
        s+=str;
        if(!root->right && !root->left){
            ans.push_back(s);
            return ;
        }
       
        s.push_back('-');
        s.push_back('>');
        if(root->right)help(root->right,ans,s);
        if(root->left)help(root->left,ans,s);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(root==NULL)return ans;
        
        help(root,ans,"");
        return ans;
    }
};