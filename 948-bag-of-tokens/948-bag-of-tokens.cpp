class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        if(tokens.size() == 0 || tokens[0] > power){
            return 0;
        }
        
        int i = 0, j = tokens.size() - 1, ans = 0;
        while(i <= j){
            if(tokens[i] <= power){
                power -= tokens[i];
                ans++;
                i++;
            }
            else{
                
                if(ans > 0){
                    if(i == j){
                        break;
                    }
                    ans--;
                    power += tokens[j];
                    j--;
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};