/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if(k <= 0 || !head) return head;
        
        int n = sizeofList(head);
        k = k%n;
        
        ListNode *p = head;
        ListNode *q = advanceSteps(head, k);
        
        while(q->next){
            p = p->next;
            q = q->next;
        }
        q->next = head;
        head = p->next;
        p->next = nullptr;
        
        return head;
    }
private:
    ListNode *advanceSteps(ListNode *p, int k){
        while(k > 0){
            p = p->next;
            k--;
        }
        return p;
    }
    int sizeofList(ListNode *head){
        int cnt = 0;
        while(head){
            cnt++;
            head = head->next;
        }
        
        return cnt;
    }
};


