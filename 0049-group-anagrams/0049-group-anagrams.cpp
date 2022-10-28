class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>>mpp; 
        map<char,int>mpp2;
        for(string &s : strs)
        {
            for(char &ch : s)
                mpp2[ch]++;
            mpp[mpp2].push_back(s);
            mpp2.clear();
        }
        vector<vector<string>> ans;
        for(auto &x : mpp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};