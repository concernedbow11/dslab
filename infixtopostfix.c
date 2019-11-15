#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

char stack[100],top=-1,b[100]="";

void push(char item,int size){ 
	if(top==size-1){
		printf("\nStack Overflow!");
	}
	else{
		printf("\nPushing %c...",item);
		stack[++top]=item;
	}
}

char pop(){
	printf("\nPopping %c...",stack[top]);
	return stack[top--];
}

int precedence(char a){
	if(a=='(')
		return(4);
	else if(a=='^')
		return(3);
	else if(a=='/'||a=='*')
		return(2);
	else if(a=='+'||a=='-')
		return(1);
	else
		return(0);
}	

char *infixtopostfix(char *a){
	int size=strlen(a),i=0;
	char c[2];
	int k=-1;
	push('(',size);
	strcat(a,")");
	while(a[i]!='\0'){
		if(a[i]=='('){
			push(a[i],size);
		}
		else if(isalpha(a[i])){
			k++;
			b[k]=a[i];
		}
		else if(a[i]==')'){
			do{
				k++;
				b[k]=pop();
			}while(stack[top]!='(');
			top--;
		}
		else{
			if(precedence(a[i])>precedence(stack[top])){
				k++;
				b[k]=pop();
				push(a[i],size);
			}
			else
				push(a[i],size);
		}
	i++;
	}
}
	
void main(){
	char a[100];
	printf("\n\nInfix to postfix Conversion\n---------------------------\n\n");
	printf("Enter the infix expression: ");
	scanf("%s",a);
	printf("\nThe infix expression you have entered is: %s",a);
	infixtopostfix(a);
	printf("\nThe converted postfix expression is: %s",b);
}
