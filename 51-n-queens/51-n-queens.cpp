class Solution {
public:
    
    
    /* when you are placing the queen at a particular row the queens that you have placed in the previous row are going to influence my current choices */
    
    
    
    //level - row to place queen
    //choice - column in the row to place queen
    //check - previous placed queen collision
    //move - place and move to next level
    
    vector<vector<string>> hiAns;
    
    int queen[10]; //queen[i] ->where is my queen in row i.
    
    bool check(int row, int col){
        for(int i = 0; i < row; i++){  /*this is like going through the previous rows */
            int prevQueenRow = i;
            int prevQueenCol = queen[i];
            
            if(prevQueenCol == col || abs(col - prevQueenCol) == abs(prevQueenRow - row)){
                return false;
            }
        
        }
        return true;
    }
    
    
    
    void rec(int level, vector<string> &board){  /* here level will be the rows  */
        
        int n = board.size();
        //pruning
        
        //base case
        
        if(level == n) { /* when we reach the nth row we are done with 1 solution of the problem */         hiAns.push_back(board);
            
            return;
            
        }
        
        //compute 
        // int ans = 0;
        
        for(int col = 0; col < n; col++){
            if(check(level, col)){   /*when you are placing the queen at (level, col) you have to check whether it is valid or not */
                
                //place the queen 
                queen[level] = col;
                board[level][col] = 'Q';
                
                //explore the option
                rec(level + 1, board);
                //revert placing the queen
                
                //in case of backtracking when you make changes to something that is common across the code make sure to revert it back.  
                queen[level] = -1;
                board[level] = string(n, '.');
            }
        }
        //return 
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        memset(queen, -1, sizeof(queen));
        rec(0, board);
        return hiAns;
    }
};