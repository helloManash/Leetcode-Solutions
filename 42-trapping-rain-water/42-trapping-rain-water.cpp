class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int lMax[size];
        int rMax[size];
        
        lMax[0] = height[0];
        for(int i = 1; i < size ; i++){
            lMax[i] = max(lMax[i - 1], height[i]);
        }
        rMax[size - 1] = height[size - 1];
        for(int i = size - 2; i >= 0; i--){
            rMax[i] = max(rMax[i + 1], height[i]);
        }
        int res = 0;
        for(int i = 1; i < size - 1; i++){
            res +=  min(lMax[i], rMax[i]) - height[i];
        }
        return res;
    }
};