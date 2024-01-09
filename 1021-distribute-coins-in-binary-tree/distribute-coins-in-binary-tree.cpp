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
    int ans;
    int excess(TreeNode*root){
        if(!root){
            return 0;
        }
        int l = excess(root->left);
        int r = excess(root->right);
        ans += abs(l) + abs(r);
        return l + r + root->val - 1;
    }
    int distributeCoins(TreeNode* root) {
        ans = 0;
        excess(root);
        return ans;
    }
};