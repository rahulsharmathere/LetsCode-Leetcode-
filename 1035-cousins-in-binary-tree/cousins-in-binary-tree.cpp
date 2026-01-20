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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            bool b1=false;
            bool b2=false;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->val==x)b1=true;
                if(curr->val==y)b2=true;

                if (curr->left && curr->right) {
                    int l = curr->left->val;
                    int r = curr->right->val;
                    if ((l == x && r == y) || (l == y && r == x))
                        return false;
                }
                if(curr->right)q.push(curr->right);
                if(curr->left)q.push(curr->left);
            }
            if(b1 && b2)return true;
            if(b1||b2)return false;
        }
        return false;
    }
};