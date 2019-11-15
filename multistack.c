#include<stdio.h>
int tops[100],sizes[100],n;

void push(int *a){
	int item,i;
	printf("\n\nEnter the item to push: ");
	scanf("%d",&item);
	printf("\nWhich stack to push the item to?: ");
	scanf("%d",&i);
	i=i-1;
	if(tops[i]==sizes[i]-1){
		printf("Stack overflow!!");
	}
	else if(tops[i]==-1){
		tops[i]=i*100/n;
		a[tops[i]]=item;
	}
	else
		a[++tops[i]]=item;
}

void pop(int *a){
	int i;
	printf("\nWhich stack to pop the item from?: ");
	scanf("%d",&i);
	i=i-1;
	if(tops[i]==-1){
		printf("\nStack underflow!!");
		return;
	}
	else if(tops[i]==sizes[i-1]+1){
		printf("\nPopped element is %d",a[tops[i]]);
		tops[i]=-1;
	}
	else{
		printf("\nPopped element is %d",a[tops[i]]);		
		tops[i]=tops[i]-1;
	}
}

void display(int *a,int i){
	i=i-1;
	int temp;
	temp=tops[i];
	while(temp>=sizes[i-1]){
		printf("\n%d",a[temp]);
		temp--;
	}
}


void main(){
	int a[100],i,choice=5;
	printf("\nEnter the number of stacks you would like to create (Array Size is 100)\n\n");
	scanf("%d",&n);
	for(i=0;i<n;++i){
		tops[i]=-1;
		sizes[i]=((i+1)*100/n);
	}
	while(choice!=4){	
		printf("\n\n\n\nMulti Stack Implementation\n\n------------------------");
		printf("\n\n1.Push \n2.Pop \n3.Print Stack \n4.Exit");
		printf("\n\nEnter the choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("\n\nPush Menu");
				push(a);
				break;
			case 2: printf("\n\nPop Menu");
				pop(a);
				break;
			case 3: printf("\nWhich stack to display? ");
				scanf("%d",&i);
				display(a,i);
				break;
			case 4: break;
			default: break;
		}
	}
}
