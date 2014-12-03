/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return nullptr;
        
        unordered_map<RandomListNode *, RandomListNode *> map;
        
        RandomListNode *p = head;
        RandomListNode dummy(0);
        RandomListNode *d = &dummy;
        
        // copy next
        while(p){
            d->next = new RandomListNode(p->label);
            d = d->next;
            map[p] = d;
            p = p->next;
        }
        
        // copy random ptrs by following next
        p = head;
        while(p){
            if(!p->random) map[p]->random = nullptr;
            else map[p]->random = map[p->random];
            p = p->next;
        }
        
        return dummy.next;
    }
};
