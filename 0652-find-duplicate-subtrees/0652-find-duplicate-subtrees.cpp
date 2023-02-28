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
    vector<TreeNode*>res;
    string getString(TreeNode* root, map<string,int>&mp){
        if(root == nullptr){
            return "n";
        }
        string s = to_string(root->val) + "," + getString(root->left, mp) + "," + getString(root->right, mp);
        if(mp[s] == 1){
            res.push_back(root);
        }
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string,int>mp;
        getString(root, mp);
        
        return res;
    }
};