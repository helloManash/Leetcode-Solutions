class Solution {
public:
    
//     one hashmap
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1, mp2;
        for(auto &n: nums1) mp1[n]++;
        
        
        
        vector<int>ans;
        
        for(int i = 0;i < nums2.size(); i++){
            if(mp1[nums2[i]] > 0){
                ans.push_back(nums2[i]);
                mp1[nums2[i]]--;
            }
        }
        
        return ans;
    }
};