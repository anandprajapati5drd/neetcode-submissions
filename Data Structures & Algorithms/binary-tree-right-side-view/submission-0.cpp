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
    void traverse(TreeNode* root, vector<int>& answer, int depth){
        if(!root) return;

        if(answer.size() == depth){
            answer.push_back(root->val);
        }

        traverse(root->right, answer, depth+1);
        traverse(root->left, answer, depth+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        traverse(root, ans, 0);

        return ans;
    }
};
