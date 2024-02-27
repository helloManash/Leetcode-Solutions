class Solution {
public:
    bool doesOverlap(vector<int>&a, vector<int>&b){
        int overlappingDist = min(a[1], b[1]) - max(a[0], b[0]);
        int l1 = a[1] - a[0], l2 = b[1] - b[0];
        if( overlappingDist == l1 || overlappingDist == l2){
            return true;
        }
        return false;
    }
    vector<int> mergeOverlap(vector<int>&a, vector<int>&b){
        return {min(a[0], b[0]), max(a[1], b[1])};
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        int n = intervals.size();
        for(int i = 0; i < n; i++){
            vector<int>currInterval = {intervals[i][0],intervals[i][1]};
            while(i < n && doesOverlap(currInterval, intervals[i])){
                currInterval = mergeOverlap(currInterval, intervals[i]);
                i++;
            }
            i--;
            ans.push_back(currInterval);
        }
        return ans.size();
    }
};