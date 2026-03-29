class Solution:

    def numIslands(self, grid: List[List[str]]) -> int:
        # traverse the matrix, for each cell:
        # define count <- 0
        # if it contains 0 then we continue to the next cell
        # else:
        # cell <-0
        # count+=1
        # run bfs starting from this cell
    
        def Traverse_dfs(grid, rowidx, colidx):
            moves = [(0,1) , (1,0), (-1,0) , (0,-1)]
            for move in moves:
                if rowidx + move[0] in range(0,len(grid)) and colidx + move[1] in range(0,len(grid[rowidx])) and  grid[rowidx + move[0]][colidx + move[1]] == "1":

                    grid[rowidx + move[0]][colidx + move[1]] = "0"
                    Traverse_dfs(grid, rowidx + move[0] , colidx + move[1])
            return

        count = 0
        for rowidx in range (len(grid)):
            for colidx in range(len(grid[rowidx])):
                if grid[rowidx][colidx] == "1":
                    count = count + 1
                    grid[rowidx][colidx] = "0"
                    Traverse_dfs(grid,rowidx,colidx)
        
        return count




        