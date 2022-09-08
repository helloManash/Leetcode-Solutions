class Solution {
public:
    vector<vector<int>>ans;
    vector<int> solution;
    void rec(int level, int target,vector<int>& candidates ){
        //base case
        if(level >= candidates.size() || target <= 0){
            if(target == 0){
                ans.push_back(solution);
            }
            return;
        }
        //compute
        if(level == 0 || candidates[level] != candidates[level-1]){
            solution.push_back(candidates[level]);
            rec(level, target-candidates[level], candidates);
            solution.pop_back();
        }
        rec(level+1, target, candidates);

    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        rec(0, target, candidates);
        return ans;
    }
};
