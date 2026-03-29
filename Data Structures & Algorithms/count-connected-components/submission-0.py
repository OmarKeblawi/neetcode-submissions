class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adjacency = {i:[] for i in range(n)}
        for edge in edges:
            adjacency[edge[0]].append(edge[1])
            adjacency[edge[1]].append(edge[0])
        
        visited = set()
        count = 0

        def dfs(node):
            visited.add(node)
            for neigh in adjacency[node]:
                if neigh not in visited:
                    dfs(neigh)
            return
        
        for i in range(n):
            if i not in visited:
                count += 1
                dfs(i)
        return count
        

        

