class Solution {
public:
    int distribute(int level, vector<int>& cookies, int k, vector<int>&child){
        if(level == cookies.size()){
            int ans = INT_MIN;
            for(auto &c: child){
                ans = max(ans, c);
            }
            return ans;
        }
        int ans = INT_MAX;
        for(int i = 0; i < k; i++){
            child[i] += cookies[level];
            ans = min(ans, distribute(level + 1, cookies,k, child));
            child[i] -= cookies[level];
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>child(k);
        return distribute(0, cookies, k, child);
    }
};