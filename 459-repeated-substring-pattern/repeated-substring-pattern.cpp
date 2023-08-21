class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int i = 1; i <= sqrt(n); i++){
            if(n % i == 0){
                if(i == n) continue;
                bool flag = false;
                for(int j = 0; j < n; j += i){
                    if(s.substr(0, i) != s.substr(j, i)){
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    return true;
                }
                if(i == 1) continue;
                flag = false;
                for(int j = 0; j < n; j += n/i){
                    if(s.substr(0, n/i) != s.substr(j, n/i)){
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    return true;
                }
            }

        }
        return false;

    }
};