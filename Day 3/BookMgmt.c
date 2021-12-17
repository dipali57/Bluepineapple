#include<stdio.h>
#include<stdlib.h>
struct Book{

	char BookName[100];

	struct Book *next;
}*head,*newn,*temp;


void create(){

	printf("Linked list is created succesfully ..! \n");

	newn=(struct Book *)malloc(sizeof(struct Book));

	printf("Enter BookName:\n");
	scanf("%[^'\n']s",newn->BookName);

	newn->next=NULL;

	if(head==NULL){
		head=temp=newn;
	}
	else{
		temp->next=newn;
		temp=newn;
	}

}

void InsertFirst(){
	newn=(struct Book*)malloc(sizeof( struct Book));

	printf("\tEnter BookName:\n");
	scanf(" %[^'\n']s",newn->BookName);

	newn->next=NULL;

	if(head==NULL){
		head=newn;
	}
	else{
		newn->next=head;
		head=newn;
	}
	
}

void InsertLast(){
	newn=(struct Book*)malloc(sizeof(struct Book));
	printf("\t Enter BookName:\n");
	scanf(" %[^'\n']s",newn->BookName);
	newn->next=NULL;

	temp=head;
	while(temp->next!=NULL){
			temp=temp->next;
	}
	temp->next=newn;

}

void DeleteFirst(){
	temp=head;
	 if(head!=NULL)
	 {
	 	head=head->next;
	 	free(temp);
	 }
}


void DeleteLast(){
	temp=head;
	if(head->next==NULL){
		free(head);
		head=NULL;
	}
	else{
		while(temp->next->next!=NULL){
			temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
	}

}
void display(){
	temp=head;
	printf("......................\n");
	printf("......Book Names......\n");
	while(temp!=NULL){
		printf(" %s \n",temp->BookName);
		temp=temp->next;
	}

	printf("......................\n");
}
int main(){

int ch=0;

printf("Book Management System !!\n");
printf("\n 1.insert first \n 2.Insert Last \n 3.Delete First \n 4.Delete Last \n 5.Print \n 0.Exit \n \n ");
create();
		while(1){
						printf("\n Enter your choice: ");
						scanf("%d",&ch);
						
						switch(ch){

							case 1:
								InsertFirst();
								break;
							case 2: 
								InsertLast();
								break;
						  case 3:
								DeleteFirst();
								break;
							case 4:
								DeleteLast();
								break;
							case 5:
								display();
								break;
							case 0:
								exit(0);
								break;
						}
		}

	return 0;

}