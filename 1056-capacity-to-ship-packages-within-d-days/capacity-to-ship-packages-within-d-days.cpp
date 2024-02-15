class Solution {
public:
    bool condition(vector<int>&weights, int days, int capacity){
        int cnt = 1, sum = 0;
        for(int i = 0; i < weights.size(); i++){
            if(capacity < weights[i]){
                return false;
            }
            if(sum + weights[i] > capacity){
                cnt++;
                sum = 0;
            }
            sum += weights[i];
        }
        return cnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long low = 1, high = 10e9;
        while(low < high){
            int mid = low + (high - low)/2;
            if(condition(weights, days, mid)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        
        return low;
    }
};