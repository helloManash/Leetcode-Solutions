/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL){
            return {};
        }
        queue<Node*> q;
        
        q.push(root);
        q.push(NULL);
        vector<vector<int>>ans;
        
        vector<int>indiAns;
        
        while(!q.empty()){
            Node * node = q.front();
            q.pop();
            
            if(node == NULL){
                ans.push_back(indiAns);
                indiAns.clear();
                    if(q.size() > 0){
                        q.push(NULL);
                    }
                continue;
            }
            else{
                indiAns.push_back(node->val);
                for(auto x: node->children){
                    q.push(x);
                }
            }
            
            
        }
        return ans;
        
        
    }
};