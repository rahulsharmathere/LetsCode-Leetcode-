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
    void makeGraph(TreeNode* root,unordered_map<int,list<int>>&adjList){
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                adjList[node->val].push_back(node->left->val);
                adjList[node->left->val].push_back(node->val);
            }
            if(node->right){
                q.push(node->right);
                adjList[node->val].push_back(node->right->val);
                adjList[node->right->val].push_back(node->val);
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        if(root==NULL) return 0;

        unordered_map<int,list<int>>adjList; 

        makeGraph(root,adjList);
        
        unordered_map<int,bool>visited;
        queue<pair<int,int>>q;
        q.push({start,0});
        visited[start]=true;

        int amtOfTime = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int node = it.first;
            int time = it.second;

            amtOfTime = max(amtOfTime,time);

            for(auto nbr:adjList[node])
            {
                if(!visited[nbr]){
                    visited[nbr]=true;
                    q.push({nbr,time+1});
                }
            }
        }

        return amtOfTime;
    }
};