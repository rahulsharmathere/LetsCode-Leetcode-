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
            int n = temp.size();

            vector<pair<int,int>> v;
            for (int i = 0; i < n; i++)
                v.push_back({temp[i], i});

            sort(v.begin(), v.end());

            vector<bool> visited(n, false);
            int swaps = 0;

            for (int i = 0; i < n; i++) {

                if (visited[i] || v[i].second == i)
                    continue;

                int cycleSize = 0;
                int j = i;

                while (!visited[j]) {
                    visited[j] = true;
                    j = v[j].second;
                    cycleSize++;
                }

                if (cycleSize > 1)
                    swaps += (cycleSize - 1);
            }

            cnt+=swaps;
        }
        return cnt;
    }
};