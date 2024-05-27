#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* nextList;
    int data;              
    struct Node* nextNode;
} Node;

Node* addNode(Node* head, int data, Node** tail) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->nextNode = NULL;
    newNode->nextList = NULL;

    if (head == NULL) {
        *tail = newNode;
        return newNode;
    } else {
        (*tail)->nextNode = newNode;
        *tail = newNode; 
        return head;
    }
}
Node* addNodeS(Node* head, int data, Node** tail) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->nextNode = NULL;
    newNode->nextList = NULL;

    if (head == NULL) {
        *tail = newNode;
        return newNode;
    } else {

        newNode->nextList=*tail;
        *tail = newNode; 
        return head;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->nextNode;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->nextNode;
        free(temp);
    }
}

int main() {
    Node* firstList = NULL; 
    Node* secondList = NULL; 
    Node *firstTail = NULL, *secondTail = NULL;
    Node* S = NULL;
    Node* p;
    int data, count = 0;

    printf("Enter a sequence of numbers (0 to end entry)\n");
    while (1) 
    {
        scanf("%d", &data);
        if (data == 0) break;
        secondList = addNode(secondList, data, &secondTail);
    }
    p = secondList;
    char c;
    getchar();
    printf("Enter a sequence of numbers (0 to end entry)\n");
    while (1)
    {
        scanf("%d", &data);
        if (data == 0) break;
        firstList = addNode(firstList, data, &firstTail);
        if (S == NULL) {S = firstList;firstTail->nextList=NULL;}
        firstTail->nextList=p;
        p = p->nextNode;
    }


    if (firstTail && secondTail) {
        firstTail->nextList = secondTail;
    }

    printf("First list:\n");
    printList(firstList);
    
    printf("second list:\n");
    printList(secondList);

    printf("Press 'a' to go left and 'd' to go right. Any other key to exit\n");
    Node *lst_ptr = firstList;
    Node* Snd_ptr = secondList;
    getchar();
    while(1) {
        char key = ' ';

        printf("Value: %d; Addr prev: %p next: %p\n", lst_ptr->data, lst_ptr->nextList, lst_ptr->nextNode);
        scanf("%c%*c", &key);
        

        printf("Key entered: '%c'\n", key);
        if (key == 'a') {
            if (lst_ptr->nextList)
                lst_ptr = lst_ptr->nextList;
            else 
                printf("Can't go here: prev is NULL\n");
            
        } else if(key == 'd') {
            if (lst_ptr->nextNode)
                lst_ptr = lst_ptr->nextNode;
            else
                printf("Can't go here: next is NULL\n");

        } else {
            printf("Exiting..\n");
            break;
        }
    }

    freeList(firstList);
    freeList(secondList);

    return 0;
}