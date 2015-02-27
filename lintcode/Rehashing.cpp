/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        int n = hashTable.size();
        int m = 2*n;
        vector<ListNode *> newHash(m);
        
        for(int i = 0; i < n; i++){
            ListNode *t = hashTable[i];
            while(t){
                ListNode *p = t;
                t = t->next;
                
                int k = (p->val%m+m)%m;
                ListNode *q = newHash[k];
                newHash[k] = p;
                p->next = q;
            }
        }
        
        return newHash;
    }
};
