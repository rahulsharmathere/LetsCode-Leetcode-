class Solution {
public:
    bool validate(TreeNode* root, long long mini, long long maxi) {
        if (!root) return true;
        if (root->val <= mini || root->val >= maxi)
            return false;
        return validate(root->left, mini, root->val) &&
               validate(root->right, root->val, maxi);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};
