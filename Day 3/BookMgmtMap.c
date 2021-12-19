#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 10

struct Book
{
    char Name[10];
    struct Book *next;
};

struct Book *array[size];


void init()
{
    int i;
    for(i = 0; i < size; i++)
        array[i] = NULL;
}


int hashCode(char *str) {
    int len=strlen(str);
    int sum=0;
    for(int i=0;i<len;i++){
        sum=sum+str[i];
    }
   return sum % 10;
}



void Insert(char *value)
{
    //create a newnode with value
    struct Book *newNode = malloc(sizeof(struct Book));
    strcpy(newNode->Name,value);
    newNode->next = NULL;

    //calculate hash key
    int key = hashCode(value);

    //check if chain[key] is empty
    if(array[key] == NULL)
        array[key] = newNode;
    //collision
    else
    {
        //add the node at the end of chain[key].
        struct Book *temp = array[key];
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}
int search(char *value)
{
    int key = hashCode(value);
    struct Book *temp = array[key];
    while(temp!=NULL)
    {
        printf("%s ",temp->Name);
         printf("%s ",value);
        if(strcmp(temp->Name,value)==0)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int delete(char *value)
{
    int key = hashCode(value);
    struct Book *temp = array[key], *dealloc;
    if(temp != NULL)
    {
        if(strcmp(temp->Name,value)==0)
        {
            dealloc = temp;
            temp = temp->next;
            free(dealloc);
            return 1;
        }
        else
        {
            while(temp->next)
            {
                if(strcmp(temp->next->Name,value)==0)
                {
                    dealloc = temp->next;
                    temp->next = temp->next->next;
                    free(dealloc);
                    return 1;
                }
                temp = temp->next;
            }
        }
    }

   return 0;
}

void print()
{
    int i;

    for(i = 0; i < size; i++)
    {
        struct Book *temp = array[i];
        printf("array[%d]-->",i);
        while(temp!=NULL)
        {
            printf("%s -->",temp->Name);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main(){

int ch=0;

char BName[20];
printf("Book Management System !!\n");
printf("\n 1.insert  \n 2.search Last \n 3.Delete First \n 4.Print \n 0.Exit \n \n ");
init();
		while(1){
					printf("\n Enter your choice: ");
					scanf("%d",&ch);
						
						switch(ch){

							case 1:
								printf("Enter Book Name: ");
								scanf(" %[^\n]s",BName);
								Insert(BName);
								break;
							case 2:
								printf("Enter book Name you want to search: ");
								scanf(" %[^\n]s",BName);
								int ret=search(BName);
                                if(ret==1){
                                    printf("\nBook found");
                                }
                                else{
                                    printf("\nBook Not found\n");
                                }
								break;
						  	case 3:
						  		printf("Enter book you want to delete: ");
						  		scanf(" %[^\n]s",BName);
								int ret1=delete(BName);
                                    if(ret1==1)
                                        printf("\n deleted successfully ");
                                    else
                                        printf("\n Book not found ");
								break;
							case 4:
								print();
								break;
					
							case 0:
								exit(0);
								break;
						}
		}

	return 0;

}