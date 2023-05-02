#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

ListNode* birlestir(ListNode* l1, ListNode* l2) {
    ListNode birlestirilmis = { 0 }, * current = &birlestirilmis;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
        }
        else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    current->next = l1 ? l1 : l2;

    return birlestirilmis.next;
}

int main() {
    ListNode l1[] = { {1, &l1[1]}, {3, &l1[2]}, {4, NULL} };
    ListNode l2[] = { {2, &l2[1]}, {4, &l2[2]}, {8, NULL} };

    ListNode* birlestirilmis = birlestir(l1, l2);

    while (birlestirilmis) {
        printf("%d ", birlestirilmis->val);
        birlestirilmis = birlestirilmis->next;
    }

    return 0;
}