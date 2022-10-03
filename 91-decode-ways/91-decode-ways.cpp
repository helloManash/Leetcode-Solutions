class Solution {
public:
    int dp[101];
    
    int rec(string &s, int idx, int n){
        if(idx < n && s[idx] == '0') return dp[idx] = 0;
        if(idx >= n) return dp[idx] = 1;
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        int ways  = 0;
        //pick one 
        ways += rec(s, idx + 1, n);
        
        if(idx + 1 < n &&((s[idx] == '1' && s[idx + 1] <= '9') || (s[idx] == '2' && s[idx+1] <= '6'))){
            ways += rec(s,idx + 2, n);
        }
        return dp[idx] = ways;
        
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        int n = s.length();
        return rec(s, 0,n);
    }
};