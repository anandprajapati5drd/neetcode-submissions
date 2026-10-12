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
    void traverse(TreeNode* root, vector<vector<int>>& res, int depth){
        if(!root) return;

        if(res.size() == depth){
            res.push_back({});
        }

        res[depth].push_back(root->val);

        traverse(root->left, res, depth+1);
        traverse(root->right, res, depth+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        traverse(root, ans, 0);

        return ans;
    }
};
