class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement = 0, count = 0, ans = 0;
        for(auto &x: nums){
            maxElement = max(maxElement, x);
        }
        for(auto &x: nums){
            if(x == maxElement){
                count++;
            }
            else{
                ans = max(count, ans);
                count = 0;
            }
            
        }
        ans = max(count, ans);
        return ans;
    }
};