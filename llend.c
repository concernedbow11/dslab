#include<stdio.h>
#include<stdlib.h>

struct LinkedList{
	int data;
	struct LinkedList *link;
};

typedef struct LinkedList *node;

node getNode(){
	node temp;
	temp=(node)malloc(sizeof(struct LinkedList));
	temp->link=NULL;
	return temp;
}

node createLL(){
	int item=0;
	node new,ptr;
	node header=getNode();
	if(header==NULL){
		printf("No node allocated");
		return NULL;
	}
	else
		header->data=0;
	printf("\nEnter the elements: (Enter -1 to stop entering)");
	ptr=header;
	while(item!=-1){
		new=getNode();
		if(new==NULL){
			printf("\nNo node allocated");
			break;
		}
		printf("\nEnter the data value: ");
		scanf("%d",&item);
		if(item==-1)
			break;
		ptr->link=new;
		new->data=item;
		new->link=NULL;
		ptr=ptr->link;
	}
	return header;
}

void displayll(node header){
	node ptr;
	ptr=header->link;
	while(ptr!=NULL){
		printf("%d <==> ",ptr->data);
		ptr=ptr->link;
	}
}

void main(){
	int x;
	node header,new,ptr;
	printf("creating new ll\n");
	header=createLL();
	printf("\n created ll is: \n");
	displayll(header);
	printf("\nenter item to insert at end: ");
	scanf("%d",&x);
	new=getNode();
	if(new==NULL)
		printf("cannot allocate memory");
	ptr=header;
	while(ptr->link!=NULL)
		ptr=ptr->link;
	ptr->link=new;
	new->link=NULL;
	new->data=x;
	displayll(header);
}
