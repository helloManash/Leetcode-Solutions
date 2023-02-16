class Solution {
public:
    
    long long sum(long long n){
        long long ans = 0;
        while(n > 0){
            int digit = n % 10;
            n /= 10;
            ans = ans + digit;
        }
        return ans;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        if(sum(n) <= target) return 0;
        long long ans = 0;
        for(int i = 0; i < 15; i++){
            int digit = n % 10;
            int diff = abs(digit - 10);
            ans += pow(10, i) * diff;
            
            n /= 10;
            n++;
            
            if(sum(n) <= target) return ans;
        }
        return ans;
    }
};