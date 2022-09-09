class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int res = 0, MaxDefend = INT_MIN;
        
        sort(properties.begin(), properties.end(), [](const auto &a, const auto &b) { 
        return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]; });
        
        for(auto x: properties){
            if(x[1] >= MaxDefend ){
                MaxDefend = x[1];
            }else{
                res++;
            }
        }
        
    
    return res;
    }
    
    // [6,3][5,5],[3,6]]
};




