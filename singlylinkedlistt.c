#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 20

struct n1 {
    int no;
    float regno;
    char name[N];
    struct n1 *next;
} *header, *current;

int assignvalues(struct n1 *new) {
    int a;
    float b;
    printf("enter the number: ");
    scanf("%d", &a);
    new->no = a;
    printf("enter the regno: ");
    scanf("%f", &b);
    new->regno = b;
    printf("enter the name: ");
    scanf("%s", new->name);
    return 0;
}

int characterisevalues() {
    struct n1 *newnode = (struct n1*) malloc (sizeof(struct n1));
    assignvalues(newnode);
    if (header == NULL) {
        header = newnode;
        current = newnode;
    }
    else {
        current->next = newnode;
        current = current->next;
    }
    return 0;
}

int insertatbeginning() {
    struct n1 *begnode = (struct n1*) malloc (sizeof(struct n1));
    struct n1 *temp = (struct n1*) malloc (sizeof(struct n1));
    assignvalues(begnode);
    
    temp = header;
    header = begnode;
    begnode->next = temp;
    return 0;
}

int insertatrandom() {
    current = header;
    struct n1 *begnode = (struct n1*) malloc (sizeof(struct n1));
    struct n1 *temp = (struct n1*) malloc (sizeof(struct n1));
    assignvalues(begnode);
    int a = 1;
    int n;
    printf("enter the positoon at which you wanr to insert the node");
    scanf("%d", &n);
    
    while (1) {
        if (a == n-1) {
            temp = current->next;
            current->next = begnode;
            begnode->next = temp;
            break;
        }
        a += 1;
        current = current->next;
    }
}

int insertatend() {
    current = header;
    struct n1 *begnode = (struct n1*) malloc (sizeof(struct n1));
    assignvalues(begnode);
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = begnode;
    begnode->next = NULL;
    return 0;
}

int insertnode() {
    printf("enter 1 to insert at beginning\n");
    printf("enter 2 to insert at random position\n");
    printf("enter 3 to insert at end\n");
    int a;
    scanf("%d", &a);
    if (a == 1) {
        insertatbeginning();
    }
    else if (a == 2) {
        insertatrandom();
    }
    else if (a == 3) {
        insertatend();
    }
    else {
        printf("enter currect numerical values");
    }
    return 0;
}

//deletion process taking place

int deleteatbeginning() {
    struct n1 *temp = (struct n1*) malloc (sizeof(struct n1));
    header = header->next;
    return 0;
}

int deleteatrandom() {
    current = header;
    struct n1 *temp = (struct n1*) malloc (sizeof(struct n1));
    int a = 1;
    int n;
    printf("enter the positoon at which you wanr to delete the node");
    scanf("%d", &n);
    
    while (1) {
        if (a == n-1) {
            temp = current->next;
            current->next = temp->next;
            temp->next = NULL;
            break;
        }
        a += 1;
        current = current->next;
    }
    return 0;
}

int deleteatend() {
    struct n1 *temp = (struct n1*) malloc (sizeof(struct n1));
    current = header;
    while (current->next->next != NULL) {
        current = current->next;
    }
    temp = current->next;
    current->next = NULL;
    return 0;
}

int deletenode() {
    printf("enter 1 to delete at beginning\n");
    printf("enter 2 to delete at random position\n");
    printf("enter 3 to delete at end\n");
    int a;
    scanf("%d", &a);
    if (a == 1) {
        deleteatbeginning();
    }
    else if (a == 2) {
        deleteatrandom();
    }
    else if (a == 3) {
        deleteatend();
    }
    else {
        printf("enter currect numerical values");
    }
    return 0;
}

int display() {
    while (current != NULL) {
        printf("the no is %d\n", current->no);
        printf("the regno is %f\n", current->regno);
        printf("the name is %s\n", current->name);
        printf("\n");
        current = current->next;
    }
    current = header;
    return 0;
}

int main() {
    while (1) {
        int a;
        printf("enter 1 to insert values or else press any other key: \n");
        scanf("%d", &a);
        if (a == 1) {
            characterisevalues();
        }
        else {
            printf("no changes made\n");
            break;
        }
    }
    current = header;
    display();
    printf("insertion process taking place\n");
    insertnode();
    current = header;
    display();
    deletenode();
    current = header;
    display();
    return 0;
}