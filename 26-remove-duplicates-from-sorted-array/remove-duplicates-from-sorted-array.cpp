class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 0;
        int size = nums.size();
        for(j = 1; j < size;j++ ){
            if(nums[j] != nums[j - 1]){
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};