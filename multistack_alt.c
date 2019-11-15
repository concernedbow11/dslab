#include<stdio.h>
#include<stdlib.h>

int a[20],b[20];

void multiple_stack(int n)
{
int i,j,k,choice;
for ( i=0;i<n;i++)
{
printf("\nenter the elements of the stack %d\n",i+1);
j=20/n;
k=((20/n)*i);
if (i!=n-1)
{
  while(k<(j*(i+1)))
{
printf("press 1 to enter an element or press 0 to stop\n");
scanf("%d",&choice);
if (choice==1)
{
scanf("%d", &a[k]);
k++;
}
else
{
b[i]=k-1;
break;
}
}
}
else
{
while(k<20)
{
                printf("press 1 to enter an element or press 0 to stop\n");
                scanf("%d",&choice);
                if (choice==1)
                {
                    scanf("%d", &a[k]);
                    k++;
                }
                else
                {
                    b[i]=k-1;
                    break;
                }
             }
}
}
}

void display_stack(int n,int m)
{
int i;
for(i=(20/n)*(m-1);i<=b[m-1];i++)
{
printf("\n%d  ",a[i]);
}
}

void push_stack(n,m)
{
    int i,choice=1,q;
    while(choice!=0)
    {
        printf("enter the element you want to push");
        scanf("%d", &q);
        if (m!=n)
        {   if (b[m-1]==((20/n)*m)-1)
            {
                printf("stack %d is full", m);
            }
            else
            {
                a[++b[m-1]]=q;
            }
        }
        else
        {
             if (b[m-1]==19)
            {
                printf("stack %d is full", m);
            }
            else
            {
                a[++b[m-1]]=q;
            }
        }
        printf("do you want to continue pushing?(1/0)");
        scanf("%d",&choice);
    }
}  
               
void main()
{
int n,h;
printf("enter the no. of stacks: ");
scanf("%d", &n);
multiple_stack(n);
printf("....... The multiple stack has been created\n");
    p
    printf("enter the stack you want to display: ");
scanf("%d",&h);
display_stack(n,h);
}
