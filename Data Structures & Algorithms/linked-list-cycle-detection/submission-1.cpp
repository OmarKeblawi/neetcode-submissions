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
    bool hasCycle(ListNode *head) {
        if(head == nullptr|| head->next == nullptr)
        return false;
    
    ListNode* fast = head->next->next;
    ListNode* slow = head->next;

    while(fast && slow != fast){
        slow = slow -> next;
        fast = fast->next;
        if(!fast) break;
        fast = fast->next; 
    }

    return fast == nullptr ? false: true;
    }
};
