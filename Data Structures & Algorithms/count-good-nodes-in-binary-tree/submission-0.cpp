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
    int helper(TreeNode* root, int maxi){
        if(!root) return 0;

        int ans;

        if(root->val >= maxi){
            ans = 1;
        }else{
            ans = 0;
        }

        maxi = max(maxi, root->val);
        ans += helper(root->left, maxi);
        ans += helper(root->right, maxi);

        return ans;
    }

    int goodNodes(TreeNode* root) {
        return helper(root, root->val);
    }
};
