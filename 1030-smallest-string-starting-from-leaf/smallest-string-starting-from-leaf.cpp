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
    string ans = "";

    void helper(TreeNode* root, string s) {
        char c = root->val + 'a';
        s = c + s;  

        if(!root->left && !root->right) {
            if(ans == "" || s < ans)
                ans = s;
            return;
        }

        if(root->left)  helper(root->left, s);
        if(root->right) helper(root->right, s);
    }

    string smallestFromLeaf(TreeNode* root) {
        helper(root, "");
        return ans;
    }
};
