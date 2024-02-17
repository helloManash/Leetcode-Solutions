class Solution {
public:
    
    bool condition(vector<int>& bloomDay, int m, int k, int day){
        int count = 0, totalBouquets = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(day >= bloomDay[i]){
                count++;
            }
            else{
                totalBouquets += count/k;
                count = 0;
            }
        }
        totalBouquets += count/k;
        return totalBouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        if((long)m * (long)k > (int)bloomDay.size()) return -1;
        int mi = 0, ma = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            mi = min(bloomDay[i], mi);
            ma = max(bloomDay[i], ma);
        }
        
        while(mi < ma){
            int mid = mi + (ma - mi)/2;
            if(condition(bloomDay,m,k,mid)){
                ma = mid;
            }
            else{
                mi = mid + 1;
            }
        }
        return mi;
    }
};