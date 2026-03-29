/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* prev = head;
        ListNode* cur = head->next;
        ListNode* tmp = cur->next;
        head -> next = nullptr;

        while(tmp != nullptr)
        {
            cur -> next = prev;
            prev = cur;
            cur = tmp;
            tmp = tmp->next;
        }
        cur-> next = prev;
        return cur;
    }
};
//  1 -> 2 -> 3 -> 4
//  1 <- 2 <- 3 
// tmp -> null , prv -> 3 , cur -> 4
// 
