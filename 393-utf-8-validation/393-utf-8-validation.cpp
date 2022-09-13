class Solution {
public:
    
    
    
    bool validUtf8(vector<int>& data) {
        
        int n_bytes = 0, mask1 = 1 << 7, mask2 = 1 << 6;
        
        for(auto num : data){
            int mask = 1 << 7;
            if(n_bytes == 0){
                while(mask & num){
                    n_bytes += 1;
                    mask = mask >> 1;
                }
                if(n_bytes == 0) continue;
                if(n_bytes == 1 || n_bytes > 4){
                    return false;
                }
                else{
                    n_bytes -= 1;
                }
            }
            else{
                if((mask1 & num) and !(mask2 & num)){
                    n_bytes -= 1;
                    
                    continue;
                } 
                return false;
            }  
        }
        return n_bytes == 0;
    }
};