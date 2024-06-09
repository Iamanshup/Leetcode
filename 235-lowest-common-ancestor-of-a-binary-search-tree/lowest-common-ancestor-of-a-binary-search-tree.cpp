/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) return lowestCommonAncestor(root, q, p);
        if (root == NULL || p == NULL || q == NULL) return NULL;

        if (root == p || root == q) return root;

        if (root->val < p->val) return lowestCommonAncestor(root->right, p, q);
        if (root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};