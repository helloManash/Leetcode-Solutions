class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int>mp;
        vector<int>arr(2,0);
        for(auto &ch: nums) mp[ch]++;
        for(int i = 1; i <= nums.size(); i++){
            if(mp[i] == 2){
                arr[0] = i;
            }
            else if(mp[i] == 0){
                arr[1] = i;
            }
        }
        return arr;
    }
};

