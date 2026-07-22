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
    int postorder(TreeNode*root,int &cnt){
        if(!root->left && !root->right){
            cnt++;
            return root->val;
        }
        int maxi = INT_MIN;
        if(root->left)maxi=max(max(maxi,postorder(root->left,cnt)),root->left->val);
        if(root->right)maxi=max(max(maxi,postorder(root->right,cnt)),root->right->val);
        if(maxi<=root->val)cnt++;
        return max(root->val,maxi);
    }
    int countDominantNodes(TreeNode* root) {
        if(!root)return 0;
        if(!root->right && !root->left)return 1;
        int cnt=0;
        int maxi=postorder(root,cnt);
        return cnt;
    }
};