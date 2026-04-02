#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* atual = head;

    while(atual != NULL) {
        struct ListNode* prox = atual->next;
        atual->next = prev;
        prev = atual;
        atual = prox;
    }

    return prev;
}
