#include <stdlib.h>
/* LeetCode: Remove Nth Node From End of List */
/* LeetCode supplies struct ListNode. */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next=head;
    struct ListNode *slow=&dummy, *fast=&dummy;
    for (int i=0; i<n; i++) fast=fast->next;
    while (fast->next) {
        slow=slow->next;
        fast=fast->next;
    }
    struct ListNode* del=slow->next;
    slow->next=del->next;
    free(del);
    return dummy.next;
}
