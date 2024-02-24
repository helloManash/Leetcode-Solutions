class Solution {
public:
    bool condition(vector<int>& ranks, int cars, long long time){
        int totalCars = 0;
        for(auto &rank: ranks){
            totalCars += sqrt((double)time/rank);
            if(totalCars>= cars){
                return true;
            }
        }
        return totalCars >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1, r = 1e18;
        while(l < r){
            long long mid = l + (r - l)/2;
            if(condition(ranks,cars,mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};