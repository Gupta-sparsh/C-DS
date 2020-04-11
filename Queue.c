#include <stdio.h>
#include<stdlib.h>
void push();
void pop();
void traverse();
int *queue,q_len;
int *front;
int *end;
int main()
{
    printf("Enter queue lenght : ");
    scanf("%d",&q_len);
    if(q_len>0)
    {
        queue = (int*)calloc(q_len,sizeof(q_len));
      	front = end = &queue[0];
    }
    
    else
    {
        printf("Enter a valid value");
        exit (0);
    }
    
    while(1)
    {
        printf("1. Push item.\n");
        printf("2. Pop item.\n");
        printf("3. Traverse.\n");
        int ch;
        scanf("%d",&ch);
             switch(ch)
            {
                case 1 : 
                        push();
                        break;
            
                case 2 :
                        pop();
                        break;
                    
                case 3 :
                        traverse();
                        break;
                default : 
                        exit(0);
        return 0;
            }
    }
}
void push()
{
    if(end != &queue[q_len])
    {
      printf("Enter the element.");
      int ele;
      scanf("%d",&ele);
      *end = ele;
      end++;
    }
    else
    {
        
        printf("Queue is full");
        printf("\n");
    }
}
void pop()
{
    if(end == front)
    {
        printf("The queue is empty.");
        printf("\n");
    }
    else
    {
        int *temp1,*temp2;
        int i=0;
        temp1 = front;
        temp2 = front+1;
        while(temp1 != end)
        {
            *temp1 = *temp2;
            temp1 = (temp1 + 1);
            temp2 = (temp2 + 1);
        }
        end--;
        printf("Item popped.");
        printf("\n");
    }
}
void traverse()
{
    if(end == front)
    {
        printf("Queue is Empty.\n");
    }
    else
    {
         int *temp;
        temp = front;
        while(temp != end)
        {
            printf("%d->",*temp);
            temp++;
        }
        printf("\n");
    }
}