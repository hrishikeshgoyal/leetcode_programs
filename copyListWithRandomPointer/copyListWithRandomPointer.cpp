






class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *p = NULL, *h=NULL, *t=NULL;
        if (head == NULL){
            return NULL;
        }
        
        //creat a new node for each node and insert its next
        p = head;
        while ( p != NULL){
            RandomListNode *node = new RandomListNode(p->label);
            node->next = p->next;
            p->next = node;
            p = node->next;
        }
        
        //copy random pointer for each new node
        p = head;
        while (p != NULL){
            if (p->random != NULL){
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        
        //break to two list
        p = head;
        h = t = head->next;
        while ( p != NULL ){
            p->next = p->next->next;
            if (t->next!=NULL){
                t->next = t->next->next;
            }
            
            p = p->next;
            t = t->next;
        }
        
        return h;
    }
};


class MySolution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {

        RandomListNode *p = NULL, *h=NULL, *t=NULL;
        //using a map to store the random pointer's postion.
        map<RandomListNode*, int> m;
        //construct the map
        int pos =0;
        for ( p = head; p != NULL; p = p->next, pos++){
            m[p] = pos;
        }
        
        //clone the linked list  (only consider the next pointer)
        //and using a vector to store each node's postion.
        vector<RandomListNode*> v;
        for (p = head; p != NULL; p = p->next){
            RandomListNode *node = new RandomListNode(p->label);
            v.push_back(node);
            if (h==NULL){
                h = t = node;
            }else{
                t->next = node;
                t = node;
            }
        }

        //p => source link head 
        //t => new link head
        //move the p and t synchronously, and 
        //     t->random = vector[ map[p->random] ];
        for (t=h, p = head; t!=NULL && p!= NULL; p=p->next, t=t->next){
            if (p->random!=NULL) {
                pos = m[p->random];
                t->random = v[pos];
            }
        }
        
        return h;
        
    }
};
