class Solution {
public:
    
    void moveZeroes(vector<int>& nums) {
        int shift = 0;
        for(int i = 0; i < nums.size(); i++){
            if(!nums[i]){
                shift++;
                continue;
            }
            nums[i - shift] = nums[i];
            if(shift){
                nums[i] = 0;
            }
        }
        
    }
};