#include<iostream>
using namespace std;

int main(){
	
int row=0,col=0;
int mat1[10][10],mat2[10][10];

	cout<<"Enter row value : ";
	cin>>row;

	cout<<"Enter row value : ";
	cin>>col;

	if(row)
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>mat1[i][j];
		}
	}

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<mat1[i][j]<<"\t";
		}
		cout<<endl;
	}


	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>mat2[i][j];
		}
	}

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<mat2[i][j]<<"\t";
		}
		cout<<endl;
	}
	int mult[row][col];

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			mult[i][j]=0;
			for(int k=0;k<row;k++){
				mult[i][j]+=mat1[i][k]*mat2[k][j];
			}

		}
	}
	cout<<"Matrix multiplication is: \n ";

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<mult[i][j]<<"\t";
		}
		cout<<"\n";
	}

	return 0;
}