#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* inverter(struct ListNode* head) {
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

bool isPalindrome(struct ListNode* head) {
    if(head == NULL || head->next == NULL) return true;

    struct ListNode *lento = head;
    struct ListNode *rapido = head;
    struct ListNode *prev = NULL;

    while(rapido != NULL && rapido->next != NULL) {
        prev = lento;
        lento = lento->next;
        rapido = rapido->next->next;
    }

    if(rapido != NULL) {
        lento = lento->next;
    }

    struct ListNode* segunda = inverter(lento);
    struct ListNode* primeira = head;

    while(segunda != NULL) {
        if(primeira->val != segunda->val) {
            return false;
        }
        primeira = primeira->next;
        segunda = segunda->next;
    }

    return true;
}
