# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        
        def find_path(current, node, queue):
            # if current == node then stack.append(current)
            # elif current < node then stack.append(current) and find_path(current.right,node,stack)
            # elif current > node then stack.append(current) and find_path(current.left,node,stack)
            queue.append(current)
            if current.val == node.val:
                return
            elif current.val < node.val:
                find_path(current.right,node,queue)
            elif current.val > node.val:
                find_path(current.left,node,queue)
        
        list_q = []
        find_path(root , q , list_q)
        list_p = []
        find_path(root , p , list_p)

        LAC = root

        for i in range(min(len(list_q),len(list_p))):
            if list_q[i] == list_p[i]:
                LAC = list_q[i]
            else:
                break
        return LAC
        
        

            
