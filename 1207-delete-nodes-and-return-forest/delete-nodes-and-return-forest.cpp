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
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        unordered_set<int>delset;  

        for(auto it : to_delete){  
            delset.insert(it);
        }
        helper(root,delset,ans);  

        if(root)ans.push_back(root);  
        return ans;

    }


    void helper(TreeNode*& root,unordered_set<int>& delset,vector<TreeNode*>&ans){

        if(!root)return;
        helper(root->left,delset,ans);  
        helper(root->right,delset,ans);
 
       if(delset.count(root->val)){ 
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            root=nullptr;
        }   
    }
};