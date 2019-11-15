#include<stdio.h>

void transpose(int a[][3]){
	int i,j,k,n;
	n=a[0][2];
	int b[n][3];
	b[0][0]=a[0][1];
	b[0][1]=a[0][0];
	b[0][2]=a[0][2];
	k=1;
	for(i=0;i<a[0][1];i++)
		for(j=1;j<=n;j++)
			if(i==a[j][1]){
				b[k][0]=i;
				b[k][1]=a[j][0];
				b[k][2]=a[j][2];
				k++;
			}
	printf("The three column representation is:\n");		
	for(i=0;i<k;++i){	
		for(j=0;j<3;++j)
			printf("%d ",b[i][j]);
		printf("\n");
	}
}

void add(int a[][3],int m,int n){
	int i,j,k,p=0,c[100][3],n1;
	printf("\nOrder of Matrix Should be %dx%d \n\nEnter the number of non zero elements: \n\n",m,n);
	scanf("%d",&n1);
	int b[n][3];
	printf("\n\nEnter the elements(row,col,value):\n");
	for(i=1;i<=n1;++i)
		scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
	b[0][2]=n1,b[0][0]=m,b[0][1]=n;
	printf("The three column representation is:\n");		
	for(i=0;i<n1+1;++i){	
		for(j=0;j<3;++j)
			printf("%d ",b[i][j]);
		printf("\n");
	}
	i=1,j=1,p=1;
	while(i<=a[0][2]||j<=a[0][2]){
		if(a[i][0]==b[j][0] && a[i][1]== b[j][1]){
			c[p][0]=a[i][0];
			c[p][1]=a[j][1];
			c[p][2]=a[i][2]+b[j][2];
			i++,j++,p++;
		}
		else if (a[i][0]<b[j][0]){
			c[p][0]=a[i][0];
			c[p][1]=a[i][1];
			c[p][2]=a[i][2];
			i++,p++;
		}
		else if (a[i][0]>b[j][0]){
			c[p][0]=b[j][0];
			c[p][1]=b[j][1];
			c[p][2]=b[j][2];
			j++,p++;
		}
		else if (a[i][0]==b[j][0]){
			if(a[i][1]<b[j][1]){
				c[p][0]=a[i][0];
				c[p][1]=a[i][1];
				c[p][2]=a[i][2];
				i++,p++;
			}
		}
		else{
			c[p][0]=b[j][0];
			c[p][1]=b[j][1];
			c[p][2]=b[j][2];
			j++,p++;
		}
	}
	c[0][0]=i,c[0][1]=j,c[0][2]=p;
	printf("The three column representation of sum is:\n");		
	for(i=0;i<p;++i){	
		for(j=0;j<3;++j)
			printf("%d ",c[i][j]);
		printf("\n");
	}
	
}
void main(){
	int m,n,k,a[10][10],b[50][3],p,i,j,ch=0;
	printf("Enter the size of the sparse matrix: \n\n");
	scanf("%d%d",&m,&n);
	printf("\n\nEnter the elements:\n");
	for(i=0;i<m;++i)
		for(j=0;j<n;++j)
			scanf("%d",&a[i][j]);
	printf("\nThe given matrix is: \n");
	for(i=0;i<m;++i){	
		for(j=0;j<n;++j)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	p=1;
	for(i=0;i<m;++i)
		for(j=0;j<n;++j)
			if(a[i][j]!=0){
				b[p][0]=i;
				b[p][1]=j;
				b[p][2]=a[i][j];
				p++;
			}
	b[0][2]=p-1,b[0][0]=m,b[0][1]=n;
	printf("The three column representation is: \n\n");
	for(i=0;i<p;++i){	
		for(j=0;j<3;++j)
			printf("%d ",b[i][j]);
		printf("\n");
	}
	while(ch!=3){
		printf("\n\nMenu\n____\n\n1. Find Transpose of Matrix \n\n2. Find sum with another matrix \n\n3.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: transpose(b);
				break;
			case 2: add(b,m,n);
				break;
			case 3: break;
			default:printf("\n Wrong choice!!!!\n\n");
			}
	}
	
}

