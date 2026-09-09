/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode a;
    a.next = head;

    struct ListNode* f = &a;
    struct ListNode* s = &a;

    for ( int i=0; i<= n; i++)
    {
        f = f->next;
    }

    while ( f != NULL)
    {
        f = f->next;
        s = s->next;
    }
    
    struct ListNode* t = s->next;
    s->next = t->next;

    return a.next;
}