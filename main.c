#include <stdio.h>
#include <malloc.h>
struct Node {
    int value;
    struct Node* next;
};
void printContent(struct Node *n);
int findValue(struct Node *n,int value);
void addNode(struct Node *n,int value);
void deleteFromTail(struct Node *n);
void reverseList(struct Node *n);
int main() {
    struct Node *head = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->value = 122;
    head->next = NULL;
    addNode(head,100);
    addNode(head,123);
    addNode(head,323);
    printContent(head);
    printf("\nNOW printing from tail to head: \n");
    reverseList(head);
    free(head);
    return 0;
}
void printContent(struct Node *n){
    while(n != NULL){
        printf("%d ",n->value);
        n = n->next;
    }
}
int findValue(struct Node *n,int value){
    int found = 0;
    struct Node *current = n;
    while(current != NULL){
        if(current->value == value){
            found = 1;
        }
        current = current->next;
    }
    return found;
}
void addNode(struct Node*n, int value){
    struct Node *current = n;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = (struct Node*)malloc(sizeof(struct Node));
    current->next->value = value;
    current->next->next = NULL;
}
void deleteFromTail(struct Node *n){
    struct Node *current = n;
    if(n->next == NULL){
        free(n);
    }
    while(current->next->next != NULL){
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}
void reverseList(struct Node *n) {
    struct Node *tail = NULL;
    struct Node *current = n;
    struct Node *head = NULL;
    while (current != NULL) {
        head = current->next;
        current->next = tail;

        tail = current;
        current = head;
    }
    n = tail;
    printContent(n);
}