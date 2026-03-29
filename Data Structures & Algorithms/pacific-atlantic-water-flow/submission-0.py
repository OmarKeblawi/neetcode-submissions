class Solution:

    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        ROWS,COLS = len(heights),len(heights[0])
        pac,atl = set() , set()

        def dfs(r , c , visited , prevHeight):
            if r >= ROWS or c >= COLS or r < 0 or c < 0 or prevHeight > heights[r][c] or (r,c) in visited:
                return
            visited.add((r,c))
            moves = [[0, -1], [0 , 1] , [-1 , 0], [1, 0]]
            for move in moves:
                dfs(r + move[0] , c + move[1] , visited , heights[r][c])
            return  

        for c in range(COLS):
            dfs( 0 , c , pac , heights[0][c])
            dfs( ROWS - 1 , c , atl , heights[ROWS - 1][c])
        
        for r in range(ROWS):
            dfs(r , 0 , pac , heights[r][0])
            dfs(r , COLS - 1 , atl , heights[r][COLS - 1])
        
        result = []
        for r in range(ROWS):
            for c in range(COLS):
                if (r , c) in pac and (r,c) in atl:
                    result.append([r,c])
        return result
    



