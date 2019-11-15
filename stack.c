#include<stdio.h>
int top=-1;
void pop(int *a){
	if(top<0){
		printf("\nStack Underflow!!");
		return;
	}
	else{
		printf("\n\nThe element popped is %d \n",a[top--]);
		return;
	}
}

void push(int *a,int size,int item){
	if(top==size-1){
		printf("Stack overflow!!");
	}
	else{
		a[++top]=item;
	}
}

void retrieve(int *a,int key){
	int i,temp[key+1],j=-1;
	if(key>top||key<0){
		printf("\nIndex out of Range!!");
		return;
	}
	else{
		while(top>key)
			temp[++j]=a[top--];
		printf("\nRetrieved element is %d",a[top--]);
		while(j>=0)
			a[++top]=temp[j--];
		i=top;	
		printf("\nCurrent Stack is: \n\n");
		while(i>=0)
			printf("%d\n",a[i--]);
	}
}



void main(){	
	int a[100],size,choice=6,item,i;
	printf("\nEnter the size of the stack you want to create\n");
	scanf("%d",&size);
	while(choice!=5){
		printf("\n\n\n\nStack - Array implementation\n\n------------------------");
		printf("\n\n1.Push \n2.Pop \n3.Retrieve m element \n4.Print Stack \n5.Exit");
		printf("\n\nEnter the choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("\n\nPush Menu");
				printf("\n\nEnter the item to push: ");
				scanf("%d",&item);
				push(a,size,item);
				break;
			case 2: printf("\n\nPop Menu");
				pop(a);
				break;
			case 3: printf("\n\nRetrieval Menu");
				printf("\n\nEnter index location to retrieve: ");
				scanf("%d",&item);
				retrieve(a,item);
				break;
			case 4: i=top;
				printf("\nCurrent Stack is: \n\n");
				while(i>=0)
					printf("%d\n",a[i--]);
				break;
			case 5: break;
			default: break;
		}
	}
}
