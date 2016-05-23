

class Solution {
    
private:
    ListNode *p1, *p2;
public:
    bool hasCycle(ListNode *head) {
        
        if (head==NULL) return false;
        p1=head;
        p2=head;
        
        while (p1!=NULL && p2!=NULL){
            
            p1=p1->next;
            
            if (p2->next == NULL) return false;
            
            p2=p2->next->next;
            
            if (p1==p2) return true;
        }
        
        return false;
        
    }  
    
    ListNode *detectCycle(ListNode *head) {
        
        if (hasCycle(head)==false){
            return NULL;
        }
        
        p1 = head;
        
        while (p1!=p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return p1;
    }
};
