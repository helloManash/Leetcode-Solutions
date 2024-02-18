class Solution {
public:
    
    bool condition(vector<int>& nums, int threshold, int divisor){
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += ceil((double)nums[i]/divisor);
            if(sum > threshold) return false;
        }
        
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = 1000000000;
        while(low < high){
            int mid = low + (high - low)/2;
            if(condition(nums, threshold,mid)){
                high = mid;
                
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};