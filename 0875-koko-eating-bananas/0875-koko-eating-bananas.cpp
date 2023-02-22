class Solution {
public:
    bool isPossible(long long k, int h, vector<int>piles){
        long long hours = 0;
        for(int i = 0; i < piles.size(); i++){
            if(piles[i] < k){
                hours++;
                continue;
            }
            hours += piles[i]/k;
            if(piles[i] % k != 0){
                hours++;
            }
            
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1, r = 0;
        for(int i = 0; i < piles.size(); i++){
            r += piles[i];
        }
        long long ans = 0;
        while(l <= r){
            long long mid = (l + r) >> 1;
            
            if(isPossible(mid, h, piles)){
                r = mid - 1;
                ans = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};