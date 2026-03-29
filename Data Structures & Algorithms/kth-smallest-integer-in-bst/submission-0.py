# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def inorder(self , root , arr):
        if not root:
            return
        self.inorder(root.left,arr)
        arr.append(root)
        right = root.right
        root=None
        self.inorder(right,arr)

        
        
        
         

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        arr = []
        self.inorder(root, arr)
        return arr[k-1].val