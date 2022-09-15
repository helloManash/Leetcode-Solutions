class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n % 2 == 1) return {};
        sort(changed.begin(), changed.end());
        
        vector<int>ans;
        for(int i = 0; i < n; i++){
            int x = changed[i];
            if(x < 0) continue;
            
            auto idx = lower_bound(begin(changed) + i + 1, end(changed), x * 2);
            
            if(idx == changed.end() ){
                return vector<int>();
            }
            else{
                if( *idx == 2 * x){
                    
                    changed[i] = -1;
                    *idx = -1;
                    ans.push_back(x);
                }
                else{
                    return {};
                }
            }
        }
        
        
        return ans;
    }
};