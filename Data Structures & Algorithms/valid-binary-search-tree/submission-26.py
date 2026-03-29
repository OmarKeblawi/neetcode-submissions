class Solution:
    def Inorder(self,root, arr):
        if not root:
            return
        self.Inorder(root.left , arr)
        arr.append(root)
        self.Inorder(root.right , arr)
        return
    
    def isValidBST(self , root):
        arr = []
        self.Inorder(root, arr)
        for i in range(len(arr) - 1):
            if arr[i].val >= arr[i+1].val:
                return False
        return True
        
    
            
        
                        
        
        
    







