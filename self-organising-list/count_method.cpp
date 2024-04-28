#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int count;
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
    newnode->count=0;
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
    while (current != NULL) {
        if (current->data == key) {
            current->count = current->count + 1;
            if (current != head) {
                node* temp = head;
                node* temp_prev = NULL;
                while (current->count < temp->count) {
                    temp_prev = temp;
                    temp = temp->next;
                }
                if (current != temp) {
                    prev->next = current->next;
                    current->next = temp;
                    if (temp == head)
                        head = current;
                    else
                        temp_prev->next = current;
                }
            }
            return 1;
        }
        prev = current;
        current = current->next;
    }
    return 0;
}
