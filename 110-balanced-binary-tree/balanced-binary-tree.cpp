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
    int dfs(TreeNode* root) {
        if (!root) return -1;
        int l = dfs(root -> left);
        int r = dfs(root -> right);
        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        return abs(dfs(root->left) - dfs(root->right)) < 2 
        && isBalanced(root->left) && isBalanced(root->right);
    }
};