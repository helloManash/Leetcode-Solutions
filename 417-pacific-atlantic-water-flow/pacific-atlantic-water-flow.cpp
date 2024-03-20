class Solution {
public:
    
    void dfs(int i, int j,vector<vector<int>>& heights, vector<vector<bool>>& ocean, int  row, int  col, int &prevHeight ){
        if(i < 0 || j < 0 || i >= row || j >= col ||  ocean[i][j] == true || prevHeight > heights[i][j]){
            return;
        }
        ocean[i][j] = true;
        
        
        
        
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0 ,1 ,0, -1};
        
        for(int k = 0; k < 4; k++){
            dfs(i + dx[k], j + dy[k], heights, ocean, row, col, heights[i][j]);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>>pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>>atlantic(heights.size(), vector<bool>(heights[0].size(), false));
        int row = heights.size();
        int col = heights[0].size();
        
        for(int i = 0; i < row; i++){
            dfs(i, 0, heights, pacific, row, col, heights[i][0]);
        }
        
        // for(int i = 0; i < heights.size(); i++){
        //     for(int j = 0; j < heights[0].size(); j++){
        //         cout<<pacific[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i = 0; i < col; i++){
            dfs(0, i, heights, pacific, row, col, heights[0][i]);
        }
        
        
        
        
        for(int i = 0; i < col; i++){
            dfs(heights.size() -1 ,i, heights, atlantic, row, col,heights[heights.size() -1][i] );
        }
        for(int i = 0; i < heights.size(); i++){
            dfs(i, heights[0].size() - 1, heights, atlantic, row, col,heights[i][heights[0].size() - 1]);
        }
        // for(int i = 0; i < heights.size(); i++){
        //     for(int j = 0; j < heights[0].size(); j++){
        //         cout<<atlantic[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
            vector<vector<int>>ans;
    for(int i = 0; i < heights.size(); i++){
        for(int j = 0; j < heights[0].size(); j++){
            if(pacific[i][j] && atlantic[i][j]){
                vector<int>v;
                v.push_back(i);
                v.push_back(j);
                ans.push_back(v);
            }
        }
    }
    return ans;
    }

};