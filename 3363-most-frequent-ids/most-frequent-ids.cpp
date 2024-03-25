class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        long long ans = 0;
        vector<long long>res;
        set<pair<long long,long long>, greater<pair<long long,long long>>>s;
        map<long long,long long>mp;
        for(int i = 0; i < nums.size(); i++){
             auto it = s.find({mp[nums[i]], nums[i]});
                
            if(it != s.end()){
               s.erase(it);
            }
            mp[nums[i]] += freq[i];
            if(mp[nums[i]] != 0){
                s.insert({mp[nums[i]], nums[i]});
            }
            if(s.empty()){
                res.push_back(0);
                continue;
            }
            ans = (*s.begin()).first;
            // cout<<ans<<endl;
            res.push_back(ans);
        }
        return res;
    }
};

/* (3,2), (2,3), 
 
*/