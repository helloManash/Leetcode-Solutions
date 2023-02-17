class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        int l_start = 0, r_start = 0;
        int l_target = 0, r_target = 0;
        
        for(auto &ch: start){
            if(ch == 'L'){
                l_start++;
            }
            else if(ch == 'R'){
                r_start++;
            }
        }
        for(auto &ch: target){
            if(ch == 'L'){
                l_target++;
            }
            else if(ch == 'R'){
                r_target++;
            }
        }
        if(l_start != l_target || r_start != r_target){
            return false;
        }
        int i_s = 0, i_t = 0;
        int r_str = 0, l_str = 0;
        
        for(; i_t < n; i_t++){
            if(target[i_t] == '_') continue;
            if(target[i_t] == 'L'){
                if(r_str > 0) return false;
                
                while(i_s < n){
                    if(start[i_s] == 'L') break;
                    if(start[i_s] == 'R') return false;
                    i_s++;
                }
                if(i_s < i_t){
                    return false;
                }
                i_s++;
            }
            else{
                while( i_s <= i_t){
                    if(start[i_s] == 'R') r_str++;
                    else if(start[i_s] == 'L') return false;
                    i_s++;
                }
                if(r_str == 0) return false;
                r_str--;
            }
        }
        return true;
    }
};