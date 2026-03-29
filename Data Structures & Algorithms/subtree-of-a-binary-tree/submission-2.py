# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p, q):
        if (p and not q) or (not p and q):
            return False
        if not p and not q:
            return True
        return p.val == q.val and self.isSameTree(p.right, q.right) and self.isSameTree(p.left,q.left)
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not root and subRoot:
            return False
        return self.isSameTree(root,subRoot) or self.isSubtree(root.right,subRoot) or self.isSubtree(root.left,subRoot)
