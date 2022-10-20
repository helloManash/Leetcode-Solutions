class Solution {
public:
    bool checkRecord(string s) {
       int i = 0, j = 0, cnt = 0;
        bool flag = true;
        while(s[i] != '\0'){
            if(s[i] == 'L'){
                while(s[j] == 'L'){
                    if(abs(i - j) >= 2){
                        flag = false;
                        break;
                    }
                    j++;
                }
                if(!flag){
                    break;
                }
                i = j;
            }
            else if(s[i] == 'A'){
                cnt++;
                if(cnt > 1){
                    flag = false;
                    break;
                }
                
                i++;
                j++;
            }
            else{
                i++;
                j++;
            }
            
        }
        
        if(flag){
            return true;
        }
        return false;
        
    }
};