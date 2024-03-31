#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void insert(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}
void deleteNode(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}
void search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            printf("Element found\n");
            return;
        }
        current = current->next;
    }
    printf("Element not found\n");
}
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d", node->data);
        if (node->next != NULL)
            printf("->");
        node = node->next;
    }
    printf("\n");
}
int main() {
    struct Node* head = NULL;
    int choice, data;
    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Search Element\n");
        printf("4. Print List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                insert(&head, data);
                printf("Element inserted.\n");
                break;
            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                printf("Element deleted.\n");
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &data);
                search(head, data);
                break;
            case 4:
                printf("Linked List: ");
                printList(head);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
