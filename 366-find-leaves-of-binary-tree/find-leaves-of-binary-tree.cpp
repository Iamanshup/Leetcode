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
private:
    map<int, vector<int>> heightToNodeMap;

    int findHeight(TreeNode* root) {
        if (!root) return 0;
        int h = 1 + max(findHeight(root -> left), findHeight(root -> right));
        heightToNodeMap[h].push_back(root -> val);
        return h;
    }
    
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        findHeight(root);
        vector<vector<int>> ans;
        for (pair<int, vector<int>> p : heightToNodeMap) {
            ans.push_back(p.second);
        }
        return ans;
    }
};