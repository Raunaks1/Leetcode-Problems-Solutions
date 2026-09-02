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
vector<vector<int>> res;
vector<int> curr;

void dfs(TreeNode* root, int target) {
    if (!root) return;

    curr.push_back(root->val);

    if (!root -> left && !root -> right && target == root->val) {
        res.push_back(curr);
    }

    dfs(root -> left, target - root -> val);
    dfs(root -> right, target - root -> val);

    curr.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int target) {
    dfs(root, target);
    return res;
}
};