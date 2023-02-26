class Solution {
public:

int dp[550][550];

int rec(int i, int j, string &s1, string &s2){
    if( i >= s1.length() && j >= s2.length()){
        return dp[i][j] = 0;
    }
    else{
        if(i >= s1.length()){
            return dp[i][j] = 1 + rec(i, j + 1, s1, s2);
        }else if(j >= s2.length()){
            return dp[i][j] = 1 + rec(i + 1, j, s1, s2);
        }
    }

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]){
        dp[i][j] = rec(i + 1, j + 1, s1, s2);
    }
    else{
        int x = rec(i, j + 1,s1, s2);
        int y =  rec(i + 1, j, s1, s2);
        int z = rec(i + 1, j + 1, s1, s2);
        dp[i][j] = 1 + min(y, min(x, z));
    }
    return dp[i][j];
}
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, word1, word2);
    }
};