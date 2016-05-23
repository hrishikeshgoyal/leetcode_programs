

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        static ListNode dummy(-1);
        dummy.next = head;
        ListNode *p = &dummy;
        
        while( p->next) {
            if (p->next->val == val) {
                p->next = p->next->next;
            }else{
                p = p->next;
            }
        }
        
        return dummy.next;
    }
};


