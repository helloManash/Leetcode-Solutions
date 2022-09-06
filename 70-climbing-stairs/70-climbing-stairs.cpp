class Solution {
public:
    
    int n;
    //the best way to design a recursion is to write the recursive problem
//     int rec(int level){   /* first we need to pass the first level  */
        
//         for(all choices){
//             if(check(valid choice)){
//                 move(choice);
//             }
//         }
        
//     } 
    
    int rec(int level, int n, vector<int> &dp){ /* ret-> number of ways to N if we are at stair level */
        
        if(dp[level] != -1){
            return dp[level];
        }
        //pruning 
        if(level > n){
            return 0;
        }
        
        //base case
        
        if(level == n){ /* when you are at the top */
            dp[level] = 1;
            return dp[level];
        }
        
        int ans = 0;
        //loop over choices
        for(int step = 1; step <= 2; step++){
            if(level + step  <= n){
                /* check -> if this is a valid choice */
                
                /* go to (level + step) and find out the number of ways from there */
                int ways = rec(level + step, n, dp);
                ans += ways;
            }
        }
        return dp[level] = ans;
        
    }
    int climbStairs(int n) {
        
        vector<int> dp(n + 1, -1);
        return rec(0, n, dp);
    }
};