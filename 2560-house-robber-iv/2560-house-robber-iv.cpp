
#define ll long long
class Solution {
public:
   
    bool check(ll max_money, const vector<int>& nums, int k){
        int last_steal_ind = INT_MAX;
        int can_steal = 0;
        
        for(int i = 0;i < nums.size(); i++){
            if(nums[i] > max_money) continue;
            if(last_steal_ind == i - 1) continue;
            can_steal++;
            last_steal_ind = i;
        }
        return (can_steal >= k);
    }
    int minCapability(vector<int>& nums, int k) {
        ll n  = nums.size();
        
        ll  l = 0, h = 1e9, ans = 0;
        while(l < h){
            int mid = (l + h) >> 1;
            if(check(mid, nums, k)){
                h = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return l;
    }
};


