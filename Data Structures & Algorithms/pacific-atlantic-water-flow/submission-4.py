class Solution:
    def pacificAtlantic(self , heights: List[List[int]]):
        ROWS, COLS = len(heights) , len(heights[0])
        pac,atl = set(), set()
        
        def dfs(row, col, visited, recentval):
            if row >= ROWS or row < 0 or col>=COLS or col<0 or recentval > heights[row][col] or (row,col) in visited:
                return
            visited.add((row,col))
            dfs(row + 1 , col , visited, heights[row][col])
            dfs(row - 1 , col , visited, heights[row][col])
            dfs(row , col + 1 , visited, heights[row][col])
            dfs(row , col - 1 , visited, heights[row][col])
        
        #dfs_rows
        for c in range(COLS):
            dfs(0 , c , pac , heights[0][c])
        #dfs_cols
        for r in range(ROWS):
            dfs(r , 0 , pac , heights[r][0])
            
        #dfs_rows
        for c in range(COLS):
            dfs(ROWS - 1, c , atl , heights[ROWS - 1][c])
        #dfs_cols
        for r in range(ROWS):
            dfs(r , COLS - 1 , atl , heights[r][COLS - 1])
        
        result = []
        for r in range(ROWS):
            for c in range(COLS):
                if (r,c) in pac and (r,c) in atl:
                    result.append([r,c])
        return result