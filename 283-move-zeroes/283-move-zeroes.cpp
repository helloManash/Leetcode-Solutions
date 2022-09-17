class Solution {
public:
    void swap(int * a, int * b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void moveZeroes(vector<int>& nums) {
        int i = 0, k = 0;
        if(nums.size() == 0 || nums.size() == 1) return;
        while(k < (int)nums.size()){
            if(nums[k] != 0){
                if(nums[i] == 0){
                    swap(&nums[k], &nums[i]);
                    
                }
                i++;
            }
            else{
                if(nums[i] != 0){
                    i++;
                }
            }
            k++;
        }
    }
};