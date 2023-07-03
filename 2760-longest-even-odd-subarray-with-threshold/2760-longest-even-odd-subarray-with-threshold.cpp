class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0, curr = 1, n = nums.size();
        
        // Check if the input vector is empty
        if (n == 0) 
            return n;
        
        for (int i = 0; i < n; i++) {
            // Check if the current number is even, less than or equal to the threshold,
            // and it is the first even number encountered in the subarray
            if (nums[i] % 2 == 0 && ans == 0 && nums[i] <= threshold) 
                ans = 1; 
            
            for (int j = i + 1; j < n; j++) {
                // Check if the current number is even, the next number is odd (alternating),
                // less than or equal to the threshold, and update the length of the current subarray
                if (nums[i] % 2 == 0 && nums[j] % 2 != nums[j - 1] % 2 && nums[j] <= threshold && nums[i] <= threshold )  {
                    curr++;
                    ans = max(ans, curr);
                } else 
                    break;
            }
            curr = 1;
        }
        
        return ans;
    }
};