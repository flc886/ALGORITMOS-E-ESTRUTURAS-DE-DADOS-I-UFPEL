#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* cabeca = NULL;
    struct ListNode* atual = NULL;

    while(list1 != NULL && list2 != NULL) {
        struct ListNode* novo = malloc(sizeof(struct ListNode));
        if(list1->val < list2->val) {
            novo->val = list1->val;
            list1 = list1->next;
        }
        else {
            novo->val = list2->val;
            list2 = list2->next;
        }

        novo->next = NULL;
        if(cabeca == NULL) {
            cabeca = novo;
            atual = novo;
        }
        else {
            atual->next = novo;
            atual = novo;
        }
    }

    while(list1 != NULL) {
        struct ListNode* novo = malloc(sizeof(struct ListNode));
        novo->val = list1->val;
        novo->next = NULL;
        atual->next = novo;
        atual = novo;
        list1 = list1->next;
    }

    while(list2 != NULL) {
        struct ListNode* novo = malloc(sizeof(struct ListNode));
        novo->val = list2->val;
        novo->next = NULL;
        atual->next = novo;
        atual = novo;
        list2 = list2->next;
    }

    return cabeca;
}
