#include <stdio.h>
#include <stdlib.h>


typedef struct node{

    int data;
    struct node* next;        

}node;

node* createNode(int x){

    node* n = malloc(sizeof(node));
    if (!n)
        exit(1);
    
    n->data = x;
    n->next = NULL;

    return n;
}

void headInsert(node** head, node* newNode){
    
    newNode->next = *head;
    *head = newNode; 
}

void tailInsert(node** head, node* newNode){
    
    if((*head) == NULL){
        *head = newNode;
        return;
    }
    node* n = *head;
    while(n->next){
        n = n->next;
    }

    n->next = newNode;
}


void MiddleInsert(node** head, node* newNode, int pos){

    
    if(pos == 1){
        headInsert(head, newNode);
        return;
    }

    int i = 1;
    node* n = *head;
    while(n->next != NULL && i < pos - 1 ){
        n = n->next;
        i++;
    }
    if (n->next == NULL && i == pos - 1 ){
        tailInsert( head, newNode);
    }
    else if (n->next == NULL && i < pos - 1){

        printf("give a valid postion motherfucker");
        return;

    }else {
        newNode->next = n->next;
        n->next = newNode;
    }
}

void deleteNode(node** head, node* delnode){
    node* n = *head;
    if (delnode == *head){
        node* tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return;
    }
    while(n->next != delnode){
        n = n->next;
    }
    n->next = delnode->next;
    free(delnode);

}

void deleteList(node** head){
    node* n = *head;
    while(n){
        node* next = n->next;   
        free(n);
        n = next;
    }
    *head = NULL;
}
int main(){

    node* head;
    head = createNode(0);
    node *n1,*n2,*n3;


    n1 = createNode(1);
    n2 = createNode(2);
    n3 = createNode(3);
    tailInsert(&head, n1);
    tailInsert(&head, n2);
    tailInsert(&head, n3);




    return 0;
}