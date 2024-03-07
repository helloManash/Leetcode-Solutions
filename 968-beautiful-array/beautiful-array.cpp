class Solution {
public:
    vector<int> beautifulArray(int n) {
        int i = 1;
        vector<int>ans;
        ans.push_back(i);
        while(ans.size() < n){
            vector<int>temp;
            for(int an: ans){
                if(2 * an - 1 <= n){
                    temp.push_back(2 * an - 1);
                }
            }
            for(int an: ans){
                if(2 * an <= n){
                    temp.push_back(2 * an );
                }
            }
            
            ans = temp;
            
        }
        return ans;
    }
};