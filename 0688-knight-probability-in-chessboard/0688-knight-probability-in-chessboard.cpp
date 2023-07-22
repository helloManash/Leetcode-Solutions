class Solution {
public:
    double solve(int r, int c, int k, int n, vector<vector<vector<double>>> &dp){
        if(r >= n || c >= n || r < 0 || c < 0){
            return 0;
        }
        if(k == 0){
            return 1;
        }
        if(dp[r][c][k] != -1){
            return dp[r][c][k];
        }
        double result = 0;
            result = solve(r - 1, c - 2, k - 1, n, dp) + 
            solve(r - 1, c + 2, k - 1, n, dp) + 
            solve(r - 2, c - 1, k - 1, n, dp) + 
            solve(r - 2, c + 1, k - 1, n, dp) + 
            solve(r + 1, c - 2, k - 1, n, dp) + 
            solve(r + 1, c + 2, k - 1, n, dp) +
            solve(r + 2, c + 1, k - 1, n, dp) +
            solve(r + 2, c - 1, k - 1, n, dp);
        return dp[r][c][k] = result/8.0;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>>dp(n, vector<vector<double>>(n, vector<double>(k+1, -1)));
        return solve(row, column, k, n, dp);
    }
};