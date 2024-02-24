class Solution {
public:
    static bool cmp(pair<int,int>&a, pair<int,int>&b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
    long long findScore(vector<int>& nums) {
        vector<pair<int,int>>arr;
        for(int i = 0; i < nums.size(); i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(), arr.end(), cmp);
        long long ans = 0;
        unordered_map<int,bool>mp;
        for(int i = 0; i < nums.size(); i++){
            int val = arr[i].first;
            int idx = arr[i].second;
            
            if(mp[idx]) continue;
            if(idx + 1 < (int)nums.size()) mp[idx + 1] = true;
            if(idx - 1 >= 0) mp[idx - 1] = true;
            
            ans += val;
        }
        return ans;
    }
};