#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ListNode ListNode;
typedef ListNode *ListNodePtr;

struct ListNode {
    char data;                      /* node data */
    struct ListNode *nextPtr;       /* pointer to next node */
};

// Function for inserting a node at the end of the list
void insertNode(ListNodePtr *head, char data){

    // Allocating memory for a new node and setting its data
    ListNodePtr  newNode = (ListNodePtr) malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->nextPtr = NULL;

    // If list is empty set head to point to new node
    if(*head == NULL){
        *head = newNode;
        return;
    }

    // Finding the last node
    ListNodePtr tail = *head;
    while(tail->nextPtr != NULL){
        tail = tail->nextPtr;
    }

    // Setting next pointer of last node of the last node to the new node
    tail->nextPtr = newNode;

}

void deleteNode(ListNodePtr *head){
    // If list is empty print a statement
    if(*head == NULL){
        printf("List is empty, cannot delete node. \n");
        return;
    }

    // If list only has one node then free the memory
    if((*head)->nextPtr == NULL){
        free(*head);
        *head = NULL;
    }

    // Traverse the list to find the second-to-last node
    ListNodePtr secondToLastNode = *head;
    while (secondToLastNode->nextPtr->nextPtr != NULL) {
        secondToLastNode = secondToLastNode->nextPtr;
    }

    // Delete the last node and set the next pointer of the second-to-last node to NULL
    free(secondToLastNode->nextPtr);
    secondToLastNode->nextPtr = NULL;
}

// Function for printing the list
void printList(ListNode* n ){
    while (n != NULL){
        printf("%c ", n-> data);;
        n = n-> nextPtr;
    }
}


int main() {
    // Declaring variables:
    int input;
    char letter;
    char data;
    int end = 0;
    int node = 0;

    // Declaring Nodes:
    ListNode* head = NULL;
    ListNode* second = NULL;
    ListNode* third = NULL;

    head = (ListNode*) malloc(sizeof(ListNode));
    second = (ListNode*) malloc(sizeof(ListNode));
    third = (ListNode*) malloc(sizeof(ListNode));

//    head-> data = 'a';
//    head-> nextPtr = second;
//
//    second-> data = 'b';
//    second-> nextPtr = third;
//
//    third-> data = 'c';
//    third-> nextPtr = NULL;

    // USER ENTERS INITIAL NODES
    printf("Please enter the number of initial nodes: ");
    scanf("%d", &input);

    for (int i = 0; i < input; i++){
        printf("Enter data for node %d:", i);
        scanf(" %c", &data);
        insertNode(&head, data);
    }
    printf("Current list is: \n");
    printList(head);


    int choice = 0;
    while (choice != 4) {
        printf("\nLinked List Menu:\n");
        printf("1. Insert Node.\n");
        printf("2. Delete Node.\n");
        printf("3. Print List.\n");
        printf("4. Exit Program.\n");

        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data for the new node: ");
                char data;
                scanf(" %c", &data);
                insertNode(&head, data);
                break;
            case 2:
                printf("Index to delete: ");

                break;
            case 3:
                printf("Current list: ");
                printList(head);
                printf("\n");
                break;
            case 4:
                printf("Thank you! \n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                break;
        }
    }

    return 0;

}
