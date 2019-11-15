#include<stdio.h>
int a[50];
int* arraycreate(int size);
void bubsort();
void selsort();
void insort();

void main(){
	int ch=0,i,j,n;
	while(ch!=4){
		printf("Enter your choice:\n__________________ \n\n1. Bubble Sort\n\n2. Insertion Sort \n\n3. Selection Sort\n\n4. Exit\n\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: bubsort();
				break;
			case 2: insort();
				break;
			case 3: selsort();
				break;
			case 4: break;
			default:printf("\n Wrong choice!!!!\n\n");
			}
		
		}
}

int* arraycreate(int size){
	int i;
	printf("\n\nEnter the elements:\n");
	for(i=0;i<size;++i)
		scanf("%d",&a[i]);
	return a;
}

void bubsort(){
	int size,i=0,j=0,swap=0,comp=0,temp,count;
	printf("\n\nEnter the size of the array you want create: ");
	scanf("%d",&size);
	arraycreate(size);
	for(i=0;i<size-1;i++){
		for(j=0;j<size-1-i;j++){
			count=0;
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				swap++;
				count++;
			}
			comp++;
		}
		if(count==0)
			break;
	}	
	printf("\n Array has been sorted.\n");
	for(i=0;i<size;i++)
		printf("\n%d",a[i]);
	printf("\n\nThe number of comparisons is: %d and the number of swaps is: %d \n\n",comp,swap);
}

void insort(){
	int i,j,key,size,temp,swap=0,comp=0;
	printf("\n\nEnter the size of the array you want create: ");
	scanf("%d",&size);
	arraycreate(size);
	for(i=1;i<=size-1;i++){
		j=i;
		while(j>=0 && a[j-1]>a[j]){
			comp++;
			temp=a[j];
			a[j]=a[j-1];
			a[j-1]=temp;
			j--;
			swap++;
		}
		comp++;
	}
	printf("\n Array has been sorted.\n");
	for(i=0;i<size;i++)
		printf("\n%d",a[i]);
	printf("\n\nThe number of comparisons is: %d and the number of swaps is: %d \n\n",comp,swap);
}

void selsort(){
	int i,j,min,swap=0,temp,comp=0,size;
	printf("\n\nEnter the size of the array you want create: ");
	scanf("%d",&size);
	arraycreate(size);
	for(i=0;i<size;i++){
		min=i;
		for(j=i+1;j<size;j++){
			comp++;
			if(a[j]<a[min]){
				min=j;
			}
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
		swap++;
	}
	printf("\n Array has been sorted.\n");
	for(i=0;i<size;i++)
		printf("\n%d",a[i]);
	printf("\n\nThe number of comparisons is: %d and the number of swaps is: %d \n\n",comp,swap);
}
