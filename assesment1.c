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

node createCLL(){
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
		new->link=header;
		ptr=ptr->link;
	}
	return header;
}

void displayCLL(node header){
	node ptr;
	ptr=header->link;
	while(ptr!=header){
		printf("%d <==> ",ptr->data);
		ptr=ptr->link;
	}
}

void merge(node header1,node header2){
	node ptr;
	ptr=header1->link;
	while(ptr!=header1){
		if(ptr->link==header1)
			break;
		ptr=ptr->link;
	}
	ptr->link=header2->link;
	while(ptr!=header2){
		if(ptr->link==header2)
			break;
		ptr=ptr->link;
	}
	ptr->link=header1;
	free(header2);
}
			
void main(){
	node header1,header2;
	printf("\nCreating First CLL...\n");
	header1=createCLL();
	printf("\nCreating Second CLL...\n");
	header2=createCLL();
	printf("The CLLs created are as follows: \n");
	printf("CLL1.. \n");
	displayCLL(header1);
	printf("\nCLL2.. \n");
	displayCLL(header2);
	printf("\n\nMerging... \n");
	merge(header1,header2);
	displayCLL(header1);
}
	
	
	
	
	
	
	
	
	
	
