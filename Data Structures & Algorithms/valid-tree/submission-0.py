class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n-1:
            return False
        adjacency = {i:[] for i in range(n)}
        for pair in edges:
            adjacency[pair[0]].append(pair[1])
            adjacency[pair[1]].append(pair[0])
        visited = set()
        def dfs(node):
            visited.add(node)
            for neigh in adjacency[node]:
                if neigh not in visited:
                    dfs(neigh)
            return
        
        dfs(0)
        return True if len(visited) == n else False
        
