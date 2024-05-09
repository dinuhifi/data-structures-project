#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
} *head;

class linkedlist{
    public:
       linkedlist(){
           head=NULL;
       }
    
       int insert(int);
       int display();
       int deleteNode(int);
       int search(int);
};

int main(){
    linkedlist l1;
    int num,n,choice;
    while(1){
        getchar();
        getchar();
        system("cls");
        printf("Enter the operation:\n1.Insert number at end\n2.Delete the number\n3.search number\n4.display\nEnter your choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the number to insert at end:\n");
                   scanf("%d",&n);
                   if(l1.insert(n)){
                    printf("Successfully inserted %d at end\n",n);
                   }
                   else{
                    printf("Failed to insert %d\n",n);
                   }
                   break;

            case 4:l1.display();
                   break;  

            case 2:printf("Enter the number to delete:\n");
                   scanf("%d",&n);
                   if(l1.deleteNode(n)){
                    printf("Successfully deleted %d\n",n);
                   }
                   else{
                    printf("Failed to delete %d\n",n);
                   }
                   break;

            case 3:printf("Enter the number to search:\n") ;
                   scanf("%d",&n);
                   l1.search(n);
                   break;          
        }
    }
}

int linkedlist::insert(int n){
    struct node *temp= (struct node *)malloc(sizeof(struct node));
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=NULL;
    temp=head;
    if(temp==NULL){
        head=newnode;
        return 1;
    }
   else{
        while(temp->next!=NULL){
        temp=temp->next;
    }
   }
    temp->next=newnode;
    return 1;
}

int linkedlist::display(){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp=head;
    if(temp==NULL){
        printf("No elements are found in the list.\n");
        return 0;
    }
    else{
        while(temp->next!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
    printf("%d\n",temp->data);
    return 1;
}

int linkedlist::deleteNode(int data) {
    node* temp = head;
    node* prev = NULL;
    while(temp) {
        if(temp->data == data) {
            if(prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            delete temp;
            return 1;
        }
        prev = temp;
        temp = temp->next;
    }
    return 0;
}

int linkedlist::search(int key)
{
    node* current = head;
    node* prev = NULL;
    node* prev_prev = NULL;
    while (current != NULL) {
        if (current->data == key) {
            if (prev_prev != NULL) {
                prev_prev->next = current;
                prev->next = current->next;
                current->next = prev;
            }
            else if (prev != NULL) {
                prev->next = current->next;
                current->next = prev;
                head = current;
            }
            printf("%d found.\n",key);
            return 1;
        }
        prev_prev = prev;
        prev = current;
        current = current->next;
    }
    printf("%d not found.\n",key);
    return 0;
}
