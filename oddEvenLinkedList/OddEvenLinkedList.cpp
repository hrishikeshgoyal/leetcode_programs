

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode* pOdd = head;
        ListNode* p = head->next;
        ListNode* pNext = NULL;
        while(p && (pNext=p->next)) {
            
            p->next = pNext->next;
            pNext->next = pOdd->next;
            pOdd->next = pNext;
            
            p = p->next;
            pOdd = pOdd->next;
        
        }
        return head;
    }
};
