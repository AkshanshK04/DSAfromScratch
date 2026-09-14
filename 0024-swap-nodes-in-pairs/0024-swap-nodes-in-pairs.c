/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if ( head ==  NULL || head->next == NULL)
        return head;

    struct ListNode d;
    d.next = head;

    struct ListNode* p = &d;
    while ( p->next != NULL && p->next->next != NULL)
    {
        struct ListNode* f = p->next;
        struct ListNode* s = f->next;

        f->next = s->next;
        s->next = f;
        p->next = s;

        p=f;
    }

    return d.next;
}