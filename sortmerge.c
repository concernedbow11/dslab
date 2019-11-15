#include<stdio.h>
void main()
{
	int a[10],b[10],c[20],size,size1,siz,i,j,temp;
	printf("\nEnter the size of the array: ");
	scanf("%d",&size1);
	printf("\nEnter the elements of array: ");
	for(i=0;i<size1;++i)
		scanf("%d",&a[i]);
	printf("\nEnter the size of the array: ");
	scanf("%d",&siz);
	printf("\nEnter the elements of array: ");
	for(j=0;j<siz;j++)
		scanf("%d",&b[j]);	
	for(i=0;i<size1;i++)
		c[i]=a[i];
	for(i=size1;i<size1+siz;++i)
		c[i]=b[i-siz];
	for(j=0;j<size1+siz;++j)
		printf("%d ",c[j]);
	i=0;
	while(i<siz-1){
		if(c[i]==c[i+1]){
			for(j=i;j<size1+siz-1;++j){
				c[j]=c[j+1];
			}
			size1+siz--;
		} 
	}
	printf("\nThe elements of the array are: \n");
	for(i=0;i<size1+siz;++i)
		printf("%d ",c[i]);

}

