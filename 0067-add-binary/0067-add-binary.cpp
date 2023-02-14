

class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length();
        int len2 = b.length();
        
        string ans = "";
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int cnt = 0, i = 0;
        for(i = 0; i < min(len1, len2); i++){
            if(cnt > 0){
                if(a[i] == '1' && b[i] == '1'){
                    ans += "1";
                    cnt = 1;
                }
                else if(a[i] == '0' && b[i] == '0'){
                    ans += "1";
                    cnt = 0;
                }
                else{
                    ans += "0";
                    cnt = 1;
                }
                
            }
            else{
                if(a[i] == '1' && b[i] == '1'){
                    ans += "0";
                    cnt = 1;
                }
                else if(a[i] == '0' && b[i] == '0'){
                    ans += "0";
                    cnt = 0;
                }
                else{
                    ans += "1";
                    cnt = 0;
                }
            }
            
        }
        for(; i < len1; i++){
            if(cnt > 0){
                if(a[i] == '1'){
                    ans += "0";
                    cnt = 1;
                }
                else{
                    ans += "1";
                    cnt = 0;
                    
                }
            }
            else{
                ans += a[i];
            }
        }
        for(; i < len2; i++){
            if(cnt > 0){
                if(b[i] == '1'){
                    ans += "0";
                    cnt = 1;
                }
                else{
                    ans += "1";
                    cnt = 0;
                    
                }
            }
            else{
                ans += b[i];
            }
        }
        if(cnt > 0){
            ans += "1";
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};