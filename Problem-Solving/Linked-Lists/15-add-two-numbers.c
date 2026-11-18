#include <stdlib.h>
/* LeetCode: Add Two Numbers */
/* LeetCode supplies struct ListNode. */
static struct ListNode* createNode(int value) {
    struct ListNode* node=malloc(sizeof(struct ListNode));
    if (!node) return NULL;
    node->val=value;
    node->next=NULL;
    return node;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    dummy.next=NULL;
    struct ListNode* tail=&dummy;
    int carry=0;
    while (l1 || l2 || carry) {
        int sum=carry+(l1 ? l1->val : 0)+(l2 ? l2->val : 0);
        struct ListNode* node=createNode(sum%10);
        if (!node) return dummy.next;
        tail->next=node;
        tail=node;
        carry=sum/10;
        if (l1) l1=l1->next;
        if (l2) l2=l2->next;
    }
    return dummy.next;
}
