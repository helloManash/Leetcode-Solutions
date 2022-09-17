class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>v(nums.size());
        int count = 0, k = 0;
        for(int i = 0;i < nums.size(); i++){
            if(nums[i]){
                v[k++] = nums[i];
            }
            else{
                count++;
            }
        }
        while(count){
            v[k++] = 0;
            count--;
        }
        for(int i = 0; i < nums.size(); i++){
            nums[i] = v[i];
        }
    }
};