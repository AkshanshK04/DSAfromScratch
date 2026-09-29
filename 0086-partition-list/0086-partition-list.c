/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode ld;
    struct ListNode gd;

    struct ListNode *l = &ld;
    struct ListNode *g = &gd;

    ld.next = NULL;
    gd.next = NULL;

    while (head != NULL) {
        if (head->val < x) {
            l->next = head;
            l = l->next;
        } else {
            g->next = head;
            g = g->next;
        }

        head = head->next;
    }

    g->next = NULL;
    l->next = gd.next;

    return ld.next;
}