#include<stdio.h>
int binrec(int mid,int beg,int end,int *a,int item)
{
	mid=(beg+end)/2;
	if(a[mid]==item){
			return mid;
		}
	else if(a[mid]>item)
		binrec(mid,beg,mid-1,a,item);
	else
		binrec(mid,beg+1,mid,a,item);
}

void main(){
	int item,i,j,size,a[10],flag=0,ctr=0,pos,beg,end,mid;
	printf("\nEnter the size of the array: ");
	scanf("%d",&size);
	printf("\nEnter the elements of array: ");
	for(i=0;i<size;++i){
		scanf("%d",&a[i]);
	}
	printf("\nEnter the element to search for: ");
	scanf("%d",&item);
	beg=0,end=size;
	printf("Found at: %d",binrec(mid,0,size,a,item)+1);
}
