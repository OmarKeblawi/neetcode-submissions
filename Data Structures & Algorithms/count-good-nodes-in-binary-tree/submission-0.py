# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        # initiate an empty
        maxValue = {}
        goodCnt = 1
        maxValue[root] = root.val
        queue = collections.deque()
        queue.append(root)
        def dfs(goodCnt):
            while queue:
                current = queue.popleft()
                if current.right:
                    queue.append(current.right)
                    if maxValue[current] <= current.right.val:
                        goodCnt += 1
                        maxValue[current.right] = current.right.val
                    else:
                        maxValue[current.right] = maxValue[current]
                if current.left:
                    queue.append(current.left)
                    if maxValue[current] <= current.left.val:
                        goodCnt += 1
                        maxValue[current.left] = current.left.val
                    else:
                        maxValue[current.left] = maxValue[current]
            return goodCnt
        return dfs(goodCnt)

                
            
                




