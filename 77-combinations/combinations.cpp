class Solution {
public:
vector<vector<int>>ans;
    void solve(int j, int k, int n, vector<int>&v){
        if(k == 0){
            ans.push_back(v);
            return;
        }

        for(int i = j; i <= n; i++){
            v.push_back(i);
            solve(i + 1,k-1, n, v);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>v;
        solve(1, k, n,v);
        return ans;
    }
};