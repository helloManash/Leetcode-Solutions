class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int j = 0, n = nums.size(), count = 0,ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                count++;
            }
            while(j < n && count > k){
                if(nums[j] == 0){
                 count--;   
                }
                j++;
            }
            ans = max(ans, i - j + 1);
            
        }
        return ans;
    }
};