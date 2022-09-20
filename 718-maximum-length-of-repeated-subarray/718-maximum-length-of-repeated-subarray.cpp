class Solution {
public:
    int ans = 0;
    int rec(int i, int j, vector<int>& nums1, vector<int>& nums2,  vector<vector<int>>&dp){
        if(i < 0 || j < 0){
            return 0;
        }
        
        if(dp[i][j] > -100){
            return dp[i][j];
        }
        
        if(nums1[i] != nums2[j]){
            dp[i][j] = 0;
        }
        else{
            dp[i][j] = 1 + rec(i - 1, j - 1, nums1, nums2, dp);
            ans = max(ans, dp[i][j]);
        }
        rec(i-1, j, nums1, nums2, dp);
        rec(i,j-1,nums1,nums2,dp);
        return dp[i][j];
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
       vector<vector<int>>dp(1050, vector<int>(1050, -100));
        rec(nums1.size() -1, nums2.size() - 1, nums1, nums2, dp);
        return ans;
    }
};