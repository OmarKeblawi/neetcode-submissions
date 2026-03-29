# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if len(lists) == 0:
            return None
        
        for i in range(1, len(lists)):
            lists[i] = self.mergeList(lists[i-1], lists[i])
        return lists[-1]

    def mergeList(self , l1 , l2):
        head = ListNode()
        cur = head

        while l1 and l2:
            mini = l1 if l1.val == min(l1.val,l2.val) else l2
            cur.next = mini
            if mini == l1:
                l1 = l1.next
            else:
                l2 = l2.next
            cur = cur.next
        if l1:
            cur.next = l1
        if l2:
            cur.next = l2

        return head.next



