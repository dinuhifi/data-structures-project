// implementing self organising list using move-to-front principle

#include <stdio.h>
#include <stdlib.h>

class self_org_list{
	struct node{
		int data; 
		node* next;
	};
	struct node* head;
	public:
	self_org_list(){
		head = NULL;
	};
	void movetofront(int);
	int insbeg(int);
	int insend(int);
	int delposn(int);
	int search(int);
	void display();
	
};

int main(){

	self_org_list l1;
	int num, choice, posn;
	while(1){
		printf("\n1. Insert Begin\n2. Delete Position\n3. Search\n4. Display\n5. Exit\n");
		printf("\nEnter your choice: \n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter number to insert: \n");
				scanf("%d", &num);
				if(l1.insbeg(num)){
					printf("successfully inserted %d. \n",num);
				}
				else{
					printf("%d cannot be inserted. \n",num);
				}
				break;
			case 2:
				l1.display();
				printf("Enter index value of number to be deleted. \n");
				scanf("%d", &posn);
				if(l1.delposn(posn)){
					printf("Number successfully deleted. \n");
				}
				else{
					printf("Number cannot be deleted. \n");
				}
				break;
			case 3:
				printf("Enter element to be searched for: \n");
				scanf("%d", &num);
				if(l1.search(num)){
					printf("Number present in list. \n");
					l1.movetofront(num);
				}
				else{
					printf("Number not present in list. \n");
				}
				break;
			case 4:
				l1.display();
				printf("\n");
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("Enter the right choice. \n");
				break;
		}			
	}
	return 0;
}

int self_org_list::insbeg(int n){
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
        if(temp->data==n){
            printf("already element is preent in the list.\n");
            return 0;
        }
        temp=temp->next;
    }
   }
   if(temp->data==n){
       printf("already element is present in the list.\n");
       return 0;
   }
    temp->next=newnode;
    return 1;
}

int self_org_list::delposn(int posn){
	struct node* newnode;
	struct node* temp;
	newnode = head;
	for(int i=0;i<posn;i++){
		temp = newnode;
		newnode = newnode->next;
		if (newnode==NULL){
			return 0;
		}
	}
	temp->next = newnode->next;
	free(newnode);
	return 1;
}

int self_org_list::search(int num){
	struct node* newnode;
	newnode = head;
	int flag = 1;
	int index = 1;
	if (newnode == NULL){
		return 0;
	}
	else{
		while(newnode!=NULL){
			if (newnode->data==num){
				return index;
				flag = 1;
			}
			else{
				flag = 0;
				index = index + 1;
			}
			newnode = newnode->next;
		}
		if (flag==0){
			return 0;
		}
	}
return 1;
}

void self_org_list::movetofront(int num){
	int posn;
	struct node* newnode;
	newnode = head;
	if (newnode==NULL){
		printf("List is empty.\n");
	}
	posn = search(num);
	if(posn){
		delposn(posn-1);
		insbeg(num);
		return;
	}
	else{
		return;
	}
}

void self_org_list::display(){
	struct node* newnode;
	newnode = head;
	while(newnode!=NULL){
		printf("%d", newnode->data);
		newnode = newnode->next;
		printf(" ");
	}
}