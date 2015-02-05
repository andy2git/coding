/**
 * Solution:
 *  nullptr    a -> b -> c
 *    pre     cur| 
 *               |
 *               reverse link one by one 
 */
struct Node{
    int val;
    Node *next;
    Node(int x): val(x), next(nullptr){}
};


Node *reverseList(Node *head){
    if(!head) return nullptr;
    if(!head->next) return head;

    Node *pre = nullptr;
    Node *cur = head;
    
    while(cur){
        Node *t = cur->next;
        cur->next = pre;
        pre = cur;
        cur = t;
    }

    return pre;
}
