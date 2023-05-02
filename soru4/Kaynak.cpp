#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node node;

node* addLists(node* l1, node* l2) {
    node* head = NULL;
    node* tail = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        sum %= 10;

        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = sum;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = head;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if (carry > 0) {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = carry;
        newNode->next = NULL;
        tail->next = newNode;
    }

    return head;
}

void printList(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    node* l1 = NULL;
    node* l2 = NULL;

    // ilk liste oluþturuluyor
    l1 = (node*)malloc(sizeof(node));
    l1->data = 2;
    l1->next = (node*)malloc(sizeof(node));
    l1->next->data = 4;
    l1->next->next = (node*)malloc(sizeof(node));
    l1->next->next->data = 3;
    l1->next->next->next = NULL;

    // ikinci liste oluþturuluyor
    l2 = (node*)malloc(sizeof(node));
    l2->data = 5;
    l2->next = (node*)malloc(sizeof(node));
    l2->next->data = 6;
    l2->next->next = (node*)malloc(sizeof(node));
    l2->next->next->data = 4;
    l2->next->next->next = NULL;

    printf("Ýlk liste:\n");
    printList(l1);

    printf("Ýkinci liste:\n");
    printList(l2);

    node* sumList = addLists(l1, l2);

    printf("Toplam liste:\n");
    printList(sumList);

    return 0;
}