class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        
        queue<array<int, 3>>q;
        vector<vector<int>>dp(row, vector<int>(col, INT_MIN));
        
        q.push({0, 0, k});
        dp[0][0] = k;
        int ans = 0;
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                array<int, 3> curr = q.front();
                q.pop();
                if(curr[0] == row - 1 && curr[1] == col - 1) return ans;
                for(int i = 0; i < 4; i++){
                    
                    int new_r = curr[0] + dir[i][0];
                    int new_c = curr[1] + dir[i][1];
                    
                    
                    if(new_r >= 0 && new_r < row && new_c >= 0 && new_c < col){
                        int remain = curr[2] - grid[new_r][new_c];
                        if(remain>= 0 && dp[new_r][new_c] < remain){
                            dp[new_r][new_c] = remain;
                            q.push({new_r, new_c, remain});
                        } 
                    }
                }
            }
            ans++;
            
        }
        return -1;
    }
};