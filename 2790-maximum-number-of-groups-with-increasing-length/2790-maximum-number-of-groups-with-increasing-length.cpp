class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        long long sum = 0, ans = 0;
        sort(usageLimits.begin(), usageLimits.end());
        for(int i = 0; i < usageLimits.size(); i++){
            sum += usageLimits[i];
            if(sum >= ((ans + 1) * (ans + 2))/2){
                ans++;
            }
        }
        return ans;
    }
};