#include<stdio.h>
void main(){
	int num,i,j,size,a[10],flag=0,ctr=0;
	printf("\nEnter the size of the array: ");
	scanf("%d",&size);
	printf("\nEnter the elements of array: ");
	for(i=0;i<size;++i){
		scanf("%d",&a[i]);
	}
	printf("\nEnter the element to search for: ");
	scanf("%d",&num);
	for(i=0;i<size;i++){
		if(a[i]==num){
			ctr++;
			printf("\nElements found at position: %d ",i+1);
			flag=1;
		}
	}
	if(flag==0){
		printf("\nElement not found!!");
	}
}
