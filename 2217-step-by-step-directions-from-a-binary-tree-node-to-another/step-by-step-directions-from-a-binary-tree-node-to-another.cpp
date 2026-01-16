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
class Solution
{
private:
    bool helper(TreeNode *root, int targetValue, string& path)
    {
        if (!root)return false;
        if (root->val == targetValue)return true;
        path.push_back('L');
        if (helper(root->left, targetValue, path))
            return true;
        path.pop_back();
        path.push_back('R');
        if (helper(root->right, targetValue, path))
            return true;
        path.pop_back();
        return false;
    }

public:
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        int n = 0;
        string pathToStart;
        helper(root, startValue, pathToStart);
        string pathToDest;
        helper(root, destValue, pathToDest);
        while (pathToStart[n] == pathToDest[n])
            n++;
        return (string(pathToStart.size()-n, 'U')+pathToDest.substr(n, pathToDest.size()-n));
    }
};