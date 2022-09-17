class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i, int j , int *row, int *col){
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        
        
        if(i < 0 || j < 0 || i >= *row || j >= *col || grid[i][j] == '0'){
            return;
        }
            if(grid[i][j] == '1'){
                grid[i][j] = '0';
            }
            
        
        
        for(int k = 0; k < 4; k++){
            dfs(grid, dx[k] + i, dy[k] + j, row, col );
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    count++;
                     dfs(grid, i, j,&row, &col );
                    
                }
            }
        }
        
        
        return count;
    }
};