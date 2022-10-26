class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2){
            return false;
        }
        map<int, int> mp;
        
        mp[0] = -1;
        int remainder = 0;;
        for(int i = 0; i < nums.size(); i++){
            remainder += nums[i];
            if(k != 0) remainder %= k;
            if(mp.count(remainder)){
                if(i - mp[remainder] > 1){
                    return true;
                }
            }
            else{
                mp[remainder] = i;
            }
            
        }
         return false;
    }
};