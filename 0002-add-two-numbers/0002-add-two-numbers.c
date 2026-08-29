/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode a;
    a.next = NULL;

    struct ListNode* tail = &a;
    int carry = 0;

    while ( l1 != 0 || l2 != 0 || carry != 0)
    {
        int sum = carry;

        if ( l1 != NULL)
        {
            sum += l1 -> val;
            l1 = l1-> next;
        }

        if ( l2 != NULL)
        {
            sum += l2 -> val;
            l2 = l2 -> next;
        }

        carry =  sum/10;
        struct ListNode* new = malloc( sizeof( struct ListNode));
        new -> val = sum%10;
        new -> next = NULL;

        tail -> next = new;
        tail = new;
    }

    return a.next;
}