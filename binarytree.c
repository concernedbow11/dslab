#include<stdio.h>
#include<stdlib.h>
int flag=0;
struct LinkedList{
	int data;
	struct LinkedList *rc;
	struct LinkedList *lc;
};

typedef struct LinkedList *node;

node root,temp,found,foundp;

node getnode(){
	node temp;
	temp=(node)malloc(sizeof(struct LinkedList));
	temp->lc=NULL;
	temp->rc=NULL;
	return temp;
}

void find(int item,node parent){
	node ptr;
	ptr=parent;
	if(ptr!=NULL){
		if(ptr->data==item){
			flag=1;
		
			found=ptr;
			return;
		}
		find(item,ptr->lc);
		find(item,ptr->rc);
	}
}

void findParent(int item,node parent){
	if(parent!=NULL){
		if (parent->rc->data==item||parent->lc->data==item){
			flag=1;
			foundp=parent;
		}	
		findParent(item,parent->lc);
    		findParent(item,parent->rc);
	}
}
	
void inorder(node root){
	node ptr;
	ptr=root;
	if(ptr!=NULL){
		inorder(ptr->lc);
		printf("%d ",ptr->data);
		inorder(ptr->rc);
	}
}

void preorder(node root){
	node ptr;
	ptr=root;
	if(ptr!=NULL){
		printf("%d ",ptr->data);
		preorder(ptr->lc);
		preorder(ptr->rc);	
	}
}

void postorder(node root){
	node ptr;
	ptr=root;
	if(ptr!=NULL){
		postorder(ptr->lc);
		postorder(ptr->rc);
		printf("%d ",ptr->data);
	}
}

void traverse(){
	printf("\nInorder:\n");
	inorder(root);
	printf("\nPreorder:\n");
	preorder(root);
	printf("\nPostorder:\n");
	postorder(root);
}

void delete(int item){
	flag=0;
	findParent(item,root);
	if(flag==1){
		printf("\nItem found!");
		if((foundp->lc->data)==item){
			if(foundp->rc==NULL&&foundp->lc==NULL)
				foundp->lc=NULL;
			else{
				printf("\nNode with item is not a leaf node!");
				return;
			}
		}
			
		else{
			if(foundp->rc==NULL&&foundp->lc==NULL)
				foundp->rc=NULL;
			else{
				printf("\nNode with item is not a leaf node!");
				return;
			}
		}
	}
	else{
		printf("\nItem not found!");
		return;
	}
}		

void insert(node prt,int item){
	int ch=0;
	node ptr,new;
	flag=0;
	find(item,root);
	if(flag==1){
		printf("\nItem Found!");
		printf("\nInsert as left or right?(1/2): ");
		scanf("%d",&ch);
		if(ch==1){
			if(found->lc!=NULL){
				printf("\nAlready has a left child!");
			}
			else{
				found->lc=prt;
				printf("\nSuccessfully inserted!");
			}
		}
		else{
			if(found->rc!=NULL){
				printf("\n Already has a right child!");
			}
			else{
				found->rc=prt;
				printf("\n Inserted successfully!");
			}
		}
	}
	else{
		printf("\nItem not found");
	}
}			
void main(){
	int ch=0,item;
	root=getnode();
	root->data=0;
	while(ch!=5){
		printf("\n\nWhat do you want to do?: ");
		printf("\n1. Create a tree (new root)\n2. Insert new child\n3. Traverse the tree\n4. Delete a leaf node\n5. Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:	printf("\n\nCreating a new root...\n");
				root=getnode();
				if(root==NULL){
					printf("\nCouldn't Create a new root!!!\b");
					return;
				}
				else{
					printf("\nEnter the value for new root: ");
					scanf("%d",&(root->data));
					printf("\nNew tree root has been succesfully created!");
				}
				break;
			case 2: printf("\n\nCreating a new child...\n________________________\n");
				temp=getnode();
				if(temp==NULL)
					printf("\nCouldn't Create a new child!!!\b");
				else{
					printf("\nEnter the value for the new child: ");
					scanf("%d",&(temp->data));
					printf("\nNew child has been successfully created!");
				}
				printf("\nEnter the value of the parent to which element has to be inserted: ");
				scanf("%d",&item);
				insert(temp,item);
				break;
			case 3: printf("\n\n Traversal...\n_____________\n");
				traverse();
				break;
			case 4: printf("\nDeletion...\n___________\n");
				printf("\nEnter the value of the element to be deleted: ");
				scanf("%d",&item);
				delete(item);
				break;
			case 5: break;
			
			default:ch=5;
				break;
		}
	}
}

















