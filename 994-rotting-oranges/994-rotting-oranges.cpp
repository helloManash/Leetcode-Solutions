class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows == 0){
            return 0;
        }
        int cols = grid[0].size();
        
        int time = -1, ones = 0;
        bool rotten = false;
        queue<pair<int,int>>q;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    ones++;
                }
            }
        }
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int,int> curr = q.front();
                q.pop();




                for(int i = 0; i < 4; i++){
                    int new_r = curr.first + dir[i][0];
                    int new_c = curr.second + dir[i][1];
                    if(new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols){
                        if(grid[new_r][new_c] == 1){

                            grid[new_r][new_c] = 2;
                            ones--;

                            q.push({new_r,new_c});
                        }
                    }
                }
            }
            time++;
            
            
            
        }
        if(ones){
            return -1;
        }
        if(time == -1){
            return 0;
        }
        return time;
        
    }
};