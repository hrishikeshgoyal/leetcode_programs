


bool hasCycle(ListNode *head) {
    if (head==NULL || head->next==NULL) return false;
    ListNode* fast=head;
    ListNode* slow=head;
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(fast != NULL && fast->next != NULL && fast != slow);
    return fast == slow? true : false;
} 
