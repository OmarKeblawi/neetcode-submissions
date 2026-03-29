# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth_aux(self, cur , depth):
        if cur == None:
            return depth
        return max(self.maxDepth_aux(cur.left,depth + 1),
        self.maxDepth_aux(cur.right,depth + 1))
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.maxDepth_aux(root , 0)
        