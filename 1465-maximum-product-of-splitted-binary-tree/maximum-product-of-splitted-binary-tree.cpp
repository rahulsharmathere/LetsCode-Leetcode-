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
    long long dfs(TreeNode* root,vector<long long>&sums){
        if(root==NULL)return 0;
        long long left=dfs(root->left,sums);
        long long right=dfs(root->right,sums);
        sums.push_back(root->val+left+right);
        return root->val+left+right;
    }
    int maxProduct(TreeNode* root) {
        int MOD=1e9+7;
        vector<long long>sums;
        long long sum = dfs(root,sums);
        long long ans=INT_MIN;
        for(auto it:sums){
            ans=max(ans,(it*(sum-it)));
        }
        return ans % MOD;
    }
};