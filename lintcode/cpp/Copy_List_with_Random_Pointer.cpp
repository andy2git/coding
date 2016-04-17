/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

/**
 * Solution: a->b->c->d
 *  1. copy head first, then copy ->x into the new list. Because the new node has not been allocated yet.
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if(!head) return nullptr;
        
        
        RandomListNode *nList = new RandomListNode(head->label);
        unordered_map<RandomListNode *, RandomListNode *> map;
        map[head] = nList;
        
        RandomListNode *p = head;
        while(p->next){
            RandomListNode *t = new RandomListNode(p->next->label);
            map[p->next] = t;
            map[p]->next = t;
            p = p->next;
        }
        
        p = head;
        while(p){
            map[p]->random = map[p->random];
            p = p->next;
        }
        
        return nList;
    }
};
