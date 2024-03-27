class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size());
        int pro1 = 1, pro2 = 1, cnt = 0;
        for(auto i: nums){
            
            pro1 *= i;
            if(i == 0){
                cnt++;
                continue;
            }
            pro2 *= i;
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                if(cnt > 1){
                    ans[i] = 0;
                    continue;
                }
                ans[i] = pro2;
                continue;
            }
            ans[i] = pro1/nums[i];
        }
        return ans;
        
    }
};