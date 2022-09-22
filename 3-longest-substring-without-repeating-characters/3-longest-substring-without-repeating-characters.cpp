class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int res = 0, j = 0;
        for(int i = 0; i <= s.length(); i++){
            if(mp[s[i]] >= 1 || i == s.length()){
                
                mp[s[i]]++;
                res = max(res, i - j);
                while(s[i] != s[j]){
                    mp[s[j]] = 0;
                    j++;
                }
                j++;
                
                continue;
            }
            
            mp[s[i]]++;
            
        }
        return res;
    }
};