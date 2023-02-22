class Solution {
public:
    bool isPossible(int days, int cap, vector<int> weights){
        int k = 1, totalWeight = 0;
        for(int i = 0;i < weights.size(); i++){
            if(weights[i] > cap){
                
                return false;
            }
            if(totalWeight + weights[i] > cap){
                k++;
                totalWeight = 0;
            }
            totalWeight += weights[i];
        }
        return k <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int h = 0;
        for(int i = 0; i < weights.size(); i++){
            h += weights[i];
        }
        int l = 1;
        int ans = 0;
        while(l <= h){
            int mid = (l + h) >> 1;
            if(isPossible(days, mid, weights)){
                h = mid - 1;
                ans = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};