class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int>s;
        for(int i = 0; i < candyType.size(); i++){
            s.insert(candyType[i]);
        }
        int n = candyType.size();
        int ans = min(n/2, (int)s.size());
        return ans;
    }
};