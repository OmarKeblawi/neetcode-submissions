# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:

        # locate the first part and the second part
        # we are going to do this using fast and slow pointers:
        slow ,fast = head, head.next
        
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # reverse the second part
        second = slow.next
        prev = slow.next = None
        while second:
            tmp = second.next 
            second.next = prev
            prev = second 
            second = tmp


        first , sec = head , prev
        while sec:
            tmp1 , tmp2 = first.next , sec.next
            first.next = sec
            sec.next = tmp1
            first , sec = tmp1 , tmp2
        




        
        
