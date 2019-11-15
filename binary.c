#include<stdio.h>
void main(){
	int item,i,j,size,a[10],flag=0,ctr=0,beg,end,mid,pos;
	printf("\nEnter the size of the array: ");
	scanf("%d",&size);
	printf("\nEnter the elements of array: ");
	for(i=0;i<size;++i){
		scanf("%d",&a[i]);
	}
	printf("\nEnter the element to search for: ");
	scanf("%d",&item);
	beg=0,end=size;
	while(beg<=end){
		mid=(beg+end)/2;
		if(a[mid]==item){
			flag=1;
			printf("\nItem found at %d",mid+1);
			pos=mid;
			while(a[--pos]==item&&pos>=0)
				printf("\nItem found at %d",pos+1);
			pos=mid;
			while(a[++pos]==item&&pos<=size)
				printf("\nItem found at %d",pos+1);
			break;
		}
		else if(a[mid]>item)
			end=mid-1;
		else
			beg=mid+1;
	}
	if(flag==0)
		printf("ITEM NOT FOUND!!");
}
