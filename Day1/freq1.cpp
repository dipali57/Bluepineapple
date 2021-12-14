#include<iostream>
using namespace std;

int main(){

long int num=0;
int freq[10]={0,0,0,0,0,0,0,0,0,0};

cout<<"Enter Num: ";
cin>>num;
int rem=0;
	while(num!=0){

		rem=num%10;	

		freq[rem]++;

		num=num/10;
	}

	for(int i=0;i<10;i++){
		cout<<"frequency of "<<i<<"is:"<<freq[i]<<endl;
	}

return 0;
}