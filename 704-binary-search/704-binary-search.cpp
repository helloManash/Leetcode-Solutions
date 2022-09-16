class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        if(nums.size() == 1){
            if(nums[0] == target){
                return 0;
            }
            else{
                return -1;
            }
        }
        auto idx = lower_bound(nums.begin(), nums.end(), target);
        if(*idx == target){
            return (idx - nums.begin());
        }
        else{
            return -1;
        }
        
    }
};