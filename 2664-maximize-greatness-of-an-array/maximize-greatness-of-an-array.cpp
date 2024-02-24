class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 0, n = nums.size(), ans = 0;
        while(i < n && j < n){
            if(nums[i] == nums[j]){
                j++;
                continue;
            }
            if(nums[i] < nums[j]){
                i++;
                j++;
                ans++;
            }
        }
        return ans;
        
    }
};



//1 1 1 2 3 3 5