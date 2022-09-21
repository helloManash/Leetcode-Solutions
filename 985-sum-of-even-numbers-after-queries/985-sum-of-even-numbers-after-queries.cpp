class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evenSum = 0;
        for(int x: nums){
            if(!(x & 1)){
                evenSum += x;
            }
        }
        vector<int>ans;
        for(auto vec: queries){
            int lastNum = nums[vec[1]];
            nums[vec[1]] += vec[0];
            if(lastNum % 2 == 0) evenSum -= lastNum;
            if(abs(nums[vec[1]]) % 2 == 0 ){
                evenSum += nums[vec[1]];
                
            }
            ans.push_back(evenSum);
        }
        return ans;
    }
};