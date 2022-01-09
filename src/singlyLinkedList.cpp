#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* bubbleSort(struct Node** headptr) {
    struct Node* head = *headptr;
    struct Node* i;
    struct Node* j;
    int temp;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = head; j->next != NULL; j = j->next) {
            if (j->data > j->next->data) {
                temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }

    return head;
}

int linearSearch(struct Node** headptr, int key) {

    struct Node* head = *headptr;
    struct Node* temp = head;
    int index = 0;
    while (temp->next != NULL) {
        if (temp->data == key)
            return index;
        temp = temp->next;
        index++;
    }

    if (temp->data == key)
        return index + 1;

    return -1;
}

void displaySinglyLinkedList(struct Node** headptr) {
    struct Node* head = *headptr;

    if (head == NULL) {
        printf("\nList is empty!\n");
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d -> NULL\n", temp->data);
    }

}

struct Node* insertAtBeginning(struct Node** headptr, int value) {
    struct Node* head = *headptr;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = NULL;
    } else {
        newNode->next = head;
    }

    head = newNode;

    return head;
}

struct Node* insertAtEnd(struct Node** headptr, int value) {
    struct Node* head = *headptr;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    return head;
}

struct Node* insertInMiddle(struct Node** headptr, int value, int index) {
    struct Node* head = *headptr;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* prev = head;
    struct Node* curr = head;

    for (int i = 0; i < index; i++) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = newNode;
    newNode->next = curr;

    return head;
}

struct Node* deleteFromBeginning(struct Node** headptr) {
    struct Node* head = *headptr;

    if (head == NULL) {
        printf("List is empty!\n");
    } else {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return head;
}

struct Node* deleteFromEnd(struct Node** headptr) {
    struct Node* head = *headptr;

    if (head == NULL) {
        printf("List is empty!\n");
    } else {
        if (head->next == NULL) {
            struct Node* temp = head;
            head = NULL;
            free(temp);
        } else {
            struct Node* prev = head;
            struct Node* curr = head;

            while (curr->next != NULL) {
                prev = curr;
                curr = curr->next;
            }

            prev->next = NULL;
            free(curr);
        }
    }

    return head;
}

struct Node* deleteFromMiddle(struct Node** headptr, int index) {
    struct Node* head = *headptr;

    struct Node* prev = head;
    struct Node* curr = head;
    for (int i = 0; i < index; i++) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    free(curr);

    return head;
}

struct Node* getMiddleNode(struct Node** headptr) {
    struct Node* head = *headptr;

    struct Node* t1 = head, *t2 = head;

    while (t2->next != NULL && t2 != NULL) {
        t1 = t1->next;
        t2 = t2->next->next;
    }

    printf("Middle Element: %d\n", t1->data);
    return t1;
}

struct Node* reverseSinglyLinkedList(struct Node** headptr) {
    struct Node* head = *headptr;

    struct Node* curr = head;
    struct Node* prev = NULL, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    return head;
}

void deleteLinkedList(struct Node** headptr) {
    struct Node* head = *headptr;
    if (head == NULL)
        return;

    deleteLinkedList(&head->next);
    free(head);
}

int main() {
    struct Node* head = NULL;
    for (int i = 10; i >= 1; i--)
        head = insertAtEnd(&head, i);


    displaySinglyLinkedList(&head);
    bubbleSort(&head);
    displaySinglyLinkedList(&head);

    deleteLinkedList(&head);
}
