class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adjacency={}
        degree_in = {}
        for i in range(numCourses):
            adjacency[i] = []
            degree_in[i] = 0
        for pair in prerequisites:
            adjacency[pair[0]].append(pair[1])
            degree_in[pair[1]] += 1
        
        stack = []
        for i in range(numCourses):
            if degree_in[i] == 0:
                stack.append(i)
        count = 0
        while stack:
            current = stack.pop()
            count += 1
            for node_out in adjacency[current]:
                degree_in[node_out] -= 1
                if degree_in[node_out] == 0:
                    stack.append(node_out)
        return True if count == numCourses else False
            


            