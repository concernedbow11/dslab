#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

int postfixeval(char *a){
	int tempstack[100],top=-1;
	int i=0;
	while(a[i]!='\0'){
		if(isalpha(a[i])){
			printf("\nEnter the value of %c: ",a[i]);
			scanf("%d",&tempstack[++top]);
		}
		else{
			if(a[i]=='^'){
				top=top-1;
				tempstack[top]=pow(tempstack[top],tempstack[top+1]);
			}
			else if(a[i]=='+'){
				top=top-1;;
				tempstack[top]=tempstack[top]+tempstack[top+1];
			}
			else if(a[i]=='-'){
				top=top-1;;
				tempstack[top]=tempstack[top]-tempstack[top+1];
			}
			else if(a[i]=='*'){
				top=top-1;;
				tempstack[top]=tempstack[top]*tempstack[top+1];
			}
			else if(a[i]=='/'){
				top=top-1;;
				tempstack[top]=tempstack[top]/tempstack[top+1];
			}
		}
		i++;
	}
	return(tempstack[top]);	
}
void main(){
	char a[100];
	int b;
	printf("\n\nPostfix Evaluation\n----------------------\n\n");
	printf("Enter the postfix expression: ");
	scanf("%s",a);
	printf("\nThe postfix expression you have entered is: %s",a);
	b=postfixeval(a);
	printf("\nThe value is: %d",b);
}
