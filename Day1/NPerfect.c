#include<stdio.h>
int main(){

long int Num=0;

printf("Enter num: ");
scanf("%ld",&Num);

  // Filter
    if(Num == 0)        // If the input number is 0
    {
        return 0;
    }

    if(Num<0){      //if the input is -ve 

      return -1;
    }

    printf("All the Perfect numbers upto N :\n ");
    for(long int i=1;i<=Num;i++){
    int sum=0;

      for(int j=1;j<i;j++){
         if(i%j==0){
           sum=sum+j;
        }
      }  
      if(sum==i)
      printf("%d ",sum);

    }

return 0;
}
