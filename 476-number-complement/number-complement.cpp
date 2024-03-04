class Solution {
public:
    int findComplement(int num) {
        long long i = 0;
            int ans = 0;
        while(num){
            if(num & (1)){
                
                
            }else{
                ans = ans + pow(2,i);
            }
            i++;
            num = num>>1;
            
        }
        return ans;
    }
};