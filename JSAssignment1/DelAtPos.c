//Remove kth node from linked list

#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;	
}*head,*temp,*newn,*temp2;


void create(){
	printf("Created successfully...!\n");
	newn=(struct Node *)malloc(sizeof(struct Node));

	printf("Enter Data:\n");
	scanf("%d",&newn->data);
	newn->next=NULL;

	if(head == NULL){
		head=temp=newn;
	}
	else{
		temp->next=newn;
		temp=newn;
	}
}
void insert(){
	newn=(struct Node*)malloc(sizeof(struct Node));
	printf("Enter data:");
	scanf("%d",&newn->data);

	newn->next=NULL;
	if(head == NULL){
		head=newn;
	}
	else{
		temp=head;
		while(temp->next != NULL){
			temp=temp->next;
		}
		temp->next=newn;
	}
	
}
int count(){
	temp=head;
	int cnt=0;
	while(temp != NULL){
		cnt++;
		temp=temp->next;
	}
	return cnt;
}
void Display(){
	temp=head;
	while(temp != NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}
void deleteAtPos(){
	
	int pos=0;
	
	A: printf("Enter k position you want to delete data:\t");
    scanf("%d",&pos);
	
	int size=0;
	size=count();

	printf("size of linked list is:%d\n",size);
	if((pos < 1)||(pos > size)){
		printf("Invalid pos...please enter valid position ...\t");
		goto A;
	}//delete node from first position
	else if(pos == 1){
		if(head != NULL){
			head = head->next;
			free(temp);
		}
	}//delete node from last position
	else if(pos == size){
		 while(temp->next->next != NULL){
                temp = temp->next;
            }
            free(temp->next);
           // temp->next = NULL;
            Display();
            printf("size of linked list is:%d\n",size);
	}
	else{
		temp = head;
        for(int i = 0; i < pos-1; i++){
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);	

        Display();
         printf("size of linked list is:%d\n",size);
	}
		//Display();
}
int main(){
	int n=0;
	create();
	printf("Enter how many nodes you want to insert:\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	insert();

	Display();
	
	deleteAtPos();
 
	return 0;
}