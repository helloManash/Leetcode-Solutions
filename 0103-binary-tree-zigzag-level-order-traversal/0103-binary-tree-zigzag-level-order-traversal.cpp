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
    map<int,vector<int>>mp;
    void dfs(int level, TreeNode * root){
        if(root == nullptr){
            return;
        }
        
        mp[level].push_back(root->val);
        dfs(level + 1, root->left);
        dfs(level + 1, root->right);
        
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        dfs(0, root);
        for(auto &[c,e]: mp){
            if(c % 2 != 0){
                reverse(e.begin(), e.end());
                ans.push_back(e);
            }
            else{
                ans.push_back(e);
            }
        }
        return ans;
    }
};