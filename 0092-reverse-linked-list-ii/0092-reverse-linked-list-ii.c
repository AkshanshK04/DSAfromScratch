/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL || left == right)
        return head;

    struct ListNode d;
    d.next = head;

    struct ListNode *p = &d;
    for (int i = 1; i < left; i++) {
        p = p->next;
    }

    struct ListNode *curr = p->next;

    for (int i = 0; i < right - left; i++) {
        struct ListNode *n = curr->next;

        curr->next = n->next;
        n->next = p->next;
        p->next = n;
    }

    return d.next;
}
