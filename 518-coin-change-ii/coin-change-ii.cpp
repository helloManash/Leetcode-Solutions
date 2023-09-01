class Solution {
public:
    int solve(vector<int> &coins, int amount, int idx, vector<vector<int>>&dp){
        if(amount == 0){
            return  1;
        }
        if(idx >= coins.size()){
            return 0;
        }
        if(dp[idx][amount] != -1){
            return dp[idx][amount];
        }
        if(amount < coins[idx]){
            return dp[idx][amount] = solve(coins, amount , idx + 1, dp);
        }
        int take = solve(coins, amount - coins[idx], idx, dp);
        int skip = solve(coins, amount, idx + 1, dp);
        return dp[idx][amount] = take + skip;
        
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount + 1, -1));
        return solve(coins, amount, 0, dp);
    }
};