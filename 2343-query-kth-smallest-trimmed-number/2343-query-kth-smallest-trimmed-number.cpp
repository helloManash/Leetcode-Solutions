class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int sz = nums.size();
        
        int strLen = nums[0].length();
        vector<int>ans(n);
        for(int i = 0; i < n; i++){
            vector<pair<string,int>>arr(sz);
            int trimLength = queries[i][1];
            for(int j = 0; j < sz; j++){
                arr[j] = make_pair(nums[j].substr(strLen - trimLength), j);
            }
            sort(arr.begin(), arr.end());
            ans[i] = arr[queries[i][0] - 1].second;
        }
        return ans;
    }
};