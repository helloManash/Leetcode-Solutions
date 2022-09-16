class Solution {
public:
    
    int rec(int i, int j, int k, vector<int>& nums, vector<int>& multipliers, int m,vector<vector<int>>&dpArr){
        if(k == m || i == m){
            
            return 0;
            
        }
        
        
        if(dpArr[i][k] != INT_MIN){
            return dpArr[i][k];
        }
        
        
        int x = nums[i]  * multipliers[k] + rec(i + 1, j, k + 1, nums, multipliers, m,dpArr);
        int y = nums[j] * multipliers[k] + rec(i, j - 1, k + 1, nums, multipliers, m,dpArr);
        dpArr[i][k] = max(x, y);
        
        return dpArr[i][k];
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>>dpArr(m, vector<int>(m, INT_MIN));
        return rec(0, n - 1, 0, nums, multipliers, m,dpArr);
        
        
    }
};