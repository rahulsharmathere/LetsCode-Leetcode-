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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        int cnt=0;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int>temp;
            for(int i=0;i<s;i++){
                TreeNode*curr=q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            map<int, int> reverseIndex;
            for(int i = 0; i < temp.size(); ++i) reverseIndex[temp[i]] = i;
            int i = 0, ans = 0;
            for(auto [k,v] : reverseIndex){
                if(v == i) { i++; continue; }
                reverseIndex[temp[i]] = v;
                swap(temp[i], temp[v]);
                ans++; i++;
            }
            cnt+=ans;
        }
        return cnt;
    }
};