/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergelists(struct ListNode* a, struct ListNode* b)
{
    struct ListNode c;
    struct ListNode* d = &c;
    c.next = NULL;

    while ( a && b)
    {
        if ( a->val <= b->val)
        {
            d->next = a;
            a = a->next;
        }
        else
        {
            d->next = b;
            b = b->next;
        }

        d = d->next;
    }

    d->next = a? a:b;
    return c.next;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if ( listsSize == 0)
        return NULL;
    
    int i = 1;
    while ( i<listsSize)
    {
        for ( int j = 0; j+i < listsSize; j += i*2)
        {
            lists[j] = mergelists(lists[j], lists[j+i]);
        }

        i*=2;
    }

    return lists[0];
}