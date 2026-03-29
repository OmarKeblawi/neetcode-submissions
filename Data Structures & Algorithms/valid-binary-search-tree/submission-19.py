# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def InorderTraverse(self, current, List):
        if not current:
            return 
            
        self.InorderTraverse(current.left,List)
        List.append(current.val)
        self.InorderTraverse(current.right,List)
        return
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        List = []
        self.InorderTraverse(root,List)
        flag = True

        for i in range(len(List) - 1):
            if List[i] >= List[i+1]:
                flag = False
        return flag
        
        