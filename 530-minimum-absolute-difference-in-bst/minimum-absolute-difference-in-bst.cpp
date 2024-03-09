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
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode *>st;
        TreeNode * curr = root;
        TreeNode * prev = nullptr;
        int res = INT_MAX;
        while(curr != nullptr || st.size() > 0){
            while(curr!= nullptr){
                st.push(curr);
                curr = curr->left;
            }
            
            curr  = st.top();
            st.pop();
            if(prev != nullptr && curr != nullptr){
                res = min(res, abs(curr->val - prev->val));
            }
            prev = curr;
            curr = curr->right;
        }
        return res;
    }
};