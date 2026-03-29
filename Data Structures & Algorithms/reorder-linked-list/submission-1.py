# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if not head.next:
            return 
        # locate the first part and the second part
        # we are going to do this using fast and slow pointers:
        slow = head
        fast = head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        # reverse the second part
        second = slow.next
        sec_next = second.next
        if sec_next:
            tmp = sec_next.next
        else:
            tmp = None
        second.next = None 
        while sec_next:
            sec_next.next = second
            second = sec_next
            sec_next = tmp
            if tmp:
                tmp = tmp.next
        
        

        # merge the two parts
        slow.next = None
        sec = second
        cur = head
        tmp = cur.next
        while sec:
            cur.next = sec
            cur = tmp
            if tmp:
                tmp = tmp.next
            tmp_s = sec.next
            sec.next = cur
            sec = tmp_s
        




        
        
