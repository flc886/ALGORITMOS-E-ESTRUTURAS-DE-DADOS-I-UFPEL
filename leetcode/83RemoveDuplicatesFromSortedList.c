#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* atual = head;

    while(atual != NULL && atual->next != NULL) {
        if(atual->val == atual->next->val) {
            atual->next = atual->next->next;
        }
        else {
            atual = atual->next;
        }
    }

    return head;
}
