class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans(nums.size());
        int i = 0, j = nums.size() - 1;
        int k = j;
        while(k >= 0){
            if(abs(nums[i]) > abs(nums[j])) ans[k--] = nums[i] * nums[i++];
            else ans[k--] = nums[j] * nums[j--];
        }
        return ans;
    }
};