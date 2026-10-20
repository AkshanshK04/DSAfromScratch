/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode a;
    a.next = head;
    struct ListNode *curr = &a;

    while (curr->next != NULL) 
    {
        if (curr->next->val == val)
            curr->next = curr->next->next;
        else
            curr = curr->next;
    }

    return a.next;
}