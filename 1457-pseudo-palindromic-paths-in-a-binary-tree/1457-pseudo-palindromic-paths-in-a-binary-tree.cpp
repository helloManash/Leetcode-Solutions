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
    
    int ans = 0;
    void dfs(TreeNode * root,vector<int> &v){
        if(root==nullptr){
            int count = 0;;
            for(auto x: v){
                // cout<<x<<" ";
                if(x & 1){
                    count++;
                }
            }
            if(count <= 1) ans++;
            // cout<<"\n";            
            return;
        }
        v[root->val]++;
        
        if(root->left != nullptr){
            dfs(root->left,v);
            if(root->right != nullptr){
                dfs(root->right,v);
            }
        }
        else if(root->right != nullptr){
            dfs(root->right,v);
            if(root->left != nullptr){
                dfs(root->left,v);
            }
        }
        else{
            dfs(nullptr, v);
        }
        v[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
         if(root == nullptr){
             return 0;
         }
        vector<int> v(10,0);
        dfs(root,v);
        return ans;
    }
};