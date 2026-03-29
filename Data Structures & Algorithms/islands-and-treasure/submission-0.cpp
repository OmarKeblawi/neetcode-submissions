#include <deque>
#include <set>
class Solution {
public:
    void bfs(vector<vector<int>>& grid, int s_row, int s_col, int ROWS, int COLS){
        const int VISITED = 0;
        std::deque<pair<int,int>> q;
        vector<vector<int>> visited(ROWS, vector<int>(COLS,1));
        q.push_back({s_row,s_col});
        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop_front();
            int row = cur.first;
            int col = cur.second;
            if(visited[row][col] == VISITED){
                continue;
            }
            visited[row][col] = VISITED;
            if(row + 1 < ROWS && grid[row+1][col] != -1){
                grid[row+1][col] = min(grid[row][col] + 1 ,  grid[row+1][col]);
                q.push_back({row+1,col});
            }
            if(row - 1 >= 0 && grid[row-1][col] != -1){
                grid[row-1][col] = min(grid[row][col] + 1 ,  grid[row-1][col]);
                q.push_back({row-1,col});
            }
            if(col + 1 < COLS && grid[row][col+1] != -1){
                grid[row][col+1] = min(grid[row][col] + 1 ,  grid[row][col+1]);
                q.push_back({row,col+1});
            }
            if(col - 1 >= 0 && grid[row][col-1] != -1){
                grid[row][col-1] = min(grid[row][col] + 1 ,  grid[row][col-1]);
                q.push_back({row,col-1});
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        for(int row = 0; row < ROWS; row++){
            for(int col = 0; col < COLS; col++){
                if(!grid[row][col]){
                    bfs(grid, row , col, ROWS, COLS);
                }
            }
        }
    }
};
