# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        # start dfs from root, hold a list of lists, while holding a 
        # pointer to the list that we added to it the most recent node
        # for each node that we traverse upon in the bfs, if its distance 
        # from root is equal to the distance of an element in the last list
        # then we append it to this list, else (then it is greater 
        # by one ) we add a new list, which will hold this specific node
        def dfs(root):
            if not root:
                return []
            result = [[root]]
            dist = {root: 0}
            queue = collections.deque()
            queue.append(root)
            current_list = result[0]
            
            while queue:
                current_node = queue.popleft()
                current_nodes = []
                if current_node.left:
                    current_nodes.append(current_node.left)
                if current_node.right:
                    current_nodes.append(current_node.right)
                for node in current_nodes:
                    dist[node] = dist[current_node] + 1
                    queue.append(node)
                if current_nodes and dist[current_nodes[0]] == dist[current_list[0]]:
                    for node in current_nodes:
                        current_list.append(node)
                elif current_nodes:
                    result.append([node for node in current_nodes])
                    current_list = result[len(result) - 1]
            return result
        
        result = dfs(root)
        value_result=[]
        for List in result:
            value_list = []
            value_result.append(value_list)
            for i in range(len(List)):
                value_list.append(List[i].val)
        return value_result
                    
            # deque <-[root] , d(root)=0, for each node other 
            # than root: d(node)=inf
            # current = deque.popleft()
            # for each of current.left and current.right:
            # we do: deque.append(node)
            # d(node) <- d(current) + 1
            # if d(current_list[0]) == d(node)
            # append the node to the current_list
            # else append to result.[node] and
            # do current_list<-result[result.len() -1].


            
