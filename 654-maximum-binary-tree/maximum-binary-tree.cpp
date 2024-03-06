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
    TreeNode * rec(vector<int>& nums, int l, int r){
        if(l > r) return nullptr;
        
        int max = 0, index = -1;
        for(int i = l; i <= r; i++){
            if(max <= nums[i]){
                max = nums[i];
                index = i;
            }
        }
         TreeNode * node = new TreeNode(max);
        node->left = rec(nums, l, index - 1);
        node->right = rec(nums, index + 1, r);
        return node;
    }
    TreeNode*constructMaximumBinaryTree(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        return rec(nums,l,r);
    }
};