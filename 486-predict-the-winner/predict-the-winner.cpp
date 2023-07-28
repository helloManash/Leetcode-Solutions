class Solution {
public:
    int solve(int i, int j, vector<int>& nums){
        if(i >= nums.size() || j < 0 || i > j){
            return 0;
        }
        if(i == j){
            return nums[i];
        }
        
        int left_score = nums[i] + min(solve(i + 2, j, nums), solve(i + 1, j - 1, nums));
        int right_score = nums[j] + min(solve(i, j - 2, nums), solve(i + 1, j - 1, nums));
        return max(left_score, right_score);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total_score = accumulate(begin(nums), end(nums),0);
        int score_p1 = solve(0, n - 1, nums);
        int score_p2 = total_score - score_p1;

        return score_p1 >= score_p2;
    }
};


