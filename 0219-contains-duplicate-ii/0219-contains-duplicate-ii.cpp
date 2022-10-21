class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>>m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]].push_back(i);
        }
        for(auto pr: m){
            vector<int> indexes = pr.second;
            if(indexes.size() > 1){
                sort(indexes.begin(), indexes.end());
                for(int i = 1; i < indexes.size(); i++){
                    if(abs(indexes[i] - indexes[i - 1]) <= k){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};