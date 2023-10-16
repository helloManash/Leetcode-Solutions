class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indDiff, int valueDiff) {
        
        int n = nums.size();
        set<pair<int,int>>s;

        // i is the left index and j is the right index for a possible i and j.
        // for every j the possible values of i if from
        // 0.....j-indDiff
        // so at every index we are adding the its possible left index

        // at i = indDiff it has only one possiblility 0 and we are adding it
        // at i = indDiff+1 we ahve two possibilities 0 and 1 but we already
        // added 0 so adding 1 is sufficient similarly for i = indDiff+ 2 adding
        // 2 is sufficient as we have already added 0 and 1 and so on till i = n.
        
        for(int i = indDiff ; i < n ; i++){

            s.insert({nums[i - indDiff], i - indDiff});

            auto p1 = *s.begin(); //taking the smallest element
            auto p2 = *s.rbegin(); // taking the largest element

            if(abs(nums[i] - p1.first) >= valueDiff){
                return {p1.second, i};
            }

            if(abs(nums[i] - p2.first) >= valueDiff){
                return {i, p2.second};
            }
        }

        return {-1, -1};
    }
};