class Solution {
public:
    int isPresent(set<int>&s, int num){
        if(s.count(num)){
            return 1;
        }
        return 0;
    }
    
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        
        int good = 0, result = 0;
        for(int i = 0; i < n; i++){
            set<int>s;
            s.insert(nums[i]);
            good = 0;
            for(int j = i + 1; j < n; j++){
                if(!s.count(nums[j])){
                    good += 1 - isPresent(s,nums[j] - 1)  - isPresent(s, nums[j] + 1);
                    
                    s.insert(nums[j]);
                }
                result += good;
                
            }
            
        }
        return result;
    }
};