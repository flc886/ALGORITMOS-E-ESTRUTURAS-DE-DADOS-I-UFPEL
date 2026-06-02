#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* merge(struct ListNode* a, struct ListNode* b) {
    if(a == NULL) return b;
    if(b == NULL) return a;

    if(a->val < b->val) {
        a->next = merge(a->next, b);
        return a;
    }
    else {
        b->next = merge(a, b->next);
        return b;
    }
}

struct ListNode* sortList(struct ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *lenta = head;
    struct ListNode *rapida = head;
    struct ListNode *prev = NULL;

    while(rapida != NULL && rapida->next != NULL) {
        prev = lenta;
        lenta = lenta->next;
        rapida = rapida->next->next;
    }

    prev->next = NULL;

    struct ListNode *esq = sortList(head);
    struct ListNode *dir = sortList(lenta);

    return merge(esq, dir);
}
