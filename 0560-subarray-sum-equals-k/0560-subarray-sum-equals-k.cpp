class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>prefSum;
        prefSum.reserve(nums.size());
        prefSum.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            prefSum .push_back(prefSum[i - 1] + nums[i]);
        }
        int ans = 0;
        map<int, int>mp;
        for(int i = 0; i < nums.size(); i++){
            if(prefSum[i] == k) ans++;
            if(mp.count(prefSum[i] - k)){
                ans += mp[prefSum[i] - k];
            }
            mp[prefSum[i]]++;
        }
        return ans;
    }
};


    