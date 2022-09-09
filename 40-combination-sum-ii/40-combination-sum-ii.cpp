class Solution {
public:
    
    
    vector<vector<int>>ans;
    vector<int>solution;
    
    void rec(int level, int target, vector<int>& candidates){
        //base case
        if(target <= 0 || level == candidates.size()){
            
            if(target == 0){
                ans.push_back(solution);
            }
            
            return;
        }
        
            
        
            solution.push_back(candidates[level]);
            
            rec(level + 1,target - candidates[level],candidates);
            solution.pop_back();
        
            while(level+1 <candidates.size() && candidates[level] == candidates[level+1]) {
                level++;
            }
            rec(level + 1, target, candidates);
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        rec(0, target, candidates);
        return ans;
    }
};