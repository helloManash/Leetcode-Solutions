class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dir[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
        vector<vector<int>>arr = board;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int cnt_1 = 0;
                for(int k = 0; k < 8; k++){
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    
                    if(x < 0 || y < 0 || x >= m || y >= n) continue;
                    cnt_1 += board[x][y] == 1? 1: 0;
                }
                if(board[i][j] == 1) {
                    if(cnt_1 > 3 || cnt_1 < 2) arr[i][j] = -2;
                }
                if(board[i][j] == 0){
                    if(cnt_1 == 3){
                        arr[i][j] = 3;
                    }
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] == -2){
                    board[i][j] = 0;
                }
                if(arr[i][j] == 3){
                    board[i][j] = 1;
                }
            }
        }
    }
};