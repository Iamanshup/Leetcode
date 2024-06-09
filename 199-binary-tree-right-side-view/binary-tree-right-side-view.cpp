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
    vector<int> ans;

    void dfs(TreeNode* root, int level) {
        if (level == ans.size()) ans.push_back(root -> val);

        if (root -> right) dfs(root->right, level+1);
        if (root -> left) dfs(root->left, level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        dfs(root, 0);
        return ans;    
    }
};