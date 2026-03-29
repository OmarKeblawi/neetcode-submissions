#include <deque>
#include <set>
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        std::deque<pair<int,int>> q;
        for(int row = 0; row < ROWS; row++){
            for(int col = 0; col < COLS; col++){
                if(!grid[row][col]){
                    q.push_back({row,col});
                }
            }
        }

        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop_front();
            int row = cur.first;
            int col = cur.second;
            if(row + 1 < ROWS && grid[row+1][col] != -1 && grid[row][col] + 1 < grid[row+1][col]){
                grid[row+1][col] = grid[row][col] + 1;
                q.push_back({row+1,col});
            }
            if(row - 1 >= 0 && grid[row-1][col] != -1 && grid[row][col] + 1 <  grid[row-1][col]){
                grid[row-1][col] = grid[row][col] + 1;
                q.push_back({row-1,col});
            }
            if(col + 1 < COLS && grid[row][col+1] != -1 && grid[row][col] + 1 <  grid[row][col+1]){
                grid[row][col+1] = grid[row][col] + 1;
                q.push_back({row,col+1});
            }
            if(col - 1 >= 0 && grid[row][col-1] != -1 && grid[row][col] + 1 <  grid[row][col-1]){
                grid[row][col-1] = grid[row][col] + 1;
                q.push_back({row,col-1});
            }
        }
    }
};
