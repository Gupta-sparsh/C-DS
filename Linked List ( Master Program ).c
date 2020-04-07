#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node node;
void insert(int x);
void traverse(void);
void delete(int x);
struct node
{
    int data;
    struct node* add;
}*curr=NULL,*root=NULL,*pre=NULL;
node *pointer1,*pointer2,*pointer3;
void insert(int x)
{
    if(root==NULL)
    {
    	root=(node*)malloc(sizeof(struct node));
    	root->data=x;
    	root->add=NULL;
    }
    else if(root->add==NULL)
    {
        pre=(node*)malloc(sizeof(struct node));
        root->add=pre;
        pre->data=x;
        pre->add=NULL;
    }
    else
    {
        pre=(node*)malloc(sizeof(struct node));
        curr=(node*)malloc(sizeof(struct node));
        pre=root;
        while(pre->add!=NULL)
        {
            pre=pre->add;
        }
        pre->add=curr;
        curr->data=x;
        curr->add=NULL;
    }
}
void traverse(void)
{
    pre=root;
    if(root==NULL)
    {
        printf("Linked List not created , Create a Link List first.");
    }
    else
    {
         pre=root;
        while(pre!=NULL)
        {
            printf("%d->",pre->data);
            pre=pre->add;
        }
        printf("NULL");
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    printf("==================================================WELCOME to LINKED LIST program===============[by $PARSH]=================");
    int data,ch;
    while(1)
    {
        printf("\n\n");
        printf("1.Create/Insert Items in Linked List \n");
        printf("2.Delete items from linked list.\n");
        printf("3.Traverse\n");
        printf("4.Quit\n");
        printf("\n\nPlease enter your choice : ");
        scanf("%d",&ch);
         switch(ch)
        {
            case 1 :
                    if(root==NULL)
                    {
                        int counter;
                        printf("How many nodes you want to insert : ");
                        scanf("%d",&counter);
                        for(int i=0;i<counter;i++)
                        {
                            printf("Enter data for node %d : ",i+1);
                            scanf("%d",&data);
                            insert(data);    
                        }
                    }
                    else
                    {
                        char choice_char;
                        int counter;
                        printf("Where you want to insert node at : \n A. At Last Position  \n B. At First Position \n C. At a given position \n");
                        scanf(" ");
                        scanf("%c",&choice_char);
                        if(choice_char=='A')
                        {
                            printf("How many nodes you want to insert : ");
                            scanf("%d",&counter);
                            for(int i=0;i<counter;i++)
                            {
                                printf("Enter data for node %d : ",i+1);
                                scanf("%d",&data);
                                insert(data);    
                            }
                            break;
                        }
                        else if(choice_char=='B')
                        {
                            pointer1=root;
                            while(pointer1->add!=NULL)
                            {
                                pointer1=pointer1->add;
                            }
                            printf("How many nodes you want to insert : ");
                            scanf("%d",&counter);
                            for(int i=0;i<counter;i++)
                            {
                                printf("Enter data for node %d : ",i+1);
                                scanf("%d",&data);
                                insert(data);    
                            }
                            pointer2=root;
                            while(pointer2->add!=NULL)
                            {
                                pointer2=pointer2->add;
                            }
                            pointer2->add=root;
                            root=pointer1->add;
                            pointer1->add=NULL;
                            break;
                        }
                        else if(choice_char=='C')
                        {
                            printf("What will be the reference :\n A. Mark the given postion by Node number. \n B. Mark the given position by data\n");
                            scanf(" %c",&choice_char);
                            if(choice_char=='A')
                            {
                                int node_num;
                                 printf("Enter the node number : ");
                                 scanf("%d",&node_num);
                                 
                                 pointer1=root;
                                 for(int i=0;i<node_num-1;i++)
                                 {
                                   pointer1=pointer1->add;
                                 }
                                 pointer2=pointer1->add;
                                 pointer3=curr;
                                  printf("How many nodes you want to insert : ");
                                  scanf("%d",&counter);
                                for(int i=0;i<counter;i++)
                                {
                                    printf("Enter data for node %d : ",i+1);
                                    scanf("%d",&data);
                                    insert(data);    
                                }
                                pointer1->add=pointer3->add;
                                curr->add=pointer2;
                                curr=pointer3;
                                pointer3->add=NULL;
                                break;
                            }
                            else if(choice_char=='B')
                            {
                                printf("Enter the data to be searched for : ");
                                scanf("%d",&data);
                                pointer1=root;
                                while(pointer1!=NULL)
                                {
                                    if(pointer1->data==data)
                                    break;
                                    else
                                    pointer1=pointer1->add;
                                }
                                if(pointer1->data!=data)
                                {
                                    printf("No such data value found . ");
                                }
                                else
                                {
                                    printf("DATA value Found !\n");
                                    
                                    pointer2=pointer1->add;
                                    pointer3=curr;
                                    printf("How many nodes you want to insert : ");
                                    scanf("%d",&counter);
                                    for(int i=0;i<counter;i++)
                                        {
                                            printf("Enter data for node %d : ",i+1);
                                            scanf("%d",&data);
                                            insert(data);    
                                        }
                                    pointer1->add=pointer3->add;
                                    curr->add=pointer2;
                                    curr=pointer3;
                                    pointer3->add=NULL;
                                }
                                    break;
                            }
                            else 
                            {
                                printf("INVALID CHOICE :-( , Try Again !!");
                                break;    
                                
                            }
                            break;
                        
                        }
                    else 
                    {
                        printf("INVALID CHOICE :-( , Try Again !!");
                        break;
                    }
                    
            case 2 :
                    printf("From where do you want to delete item from the linked list :\n A. From Last \n B. From First Position \n C. From a given position\n");
                    scanf(" %c",&choice_char);
                    if(choice_char=='A')
                    {
                        pointer1=root;
                        pointer2=root;
                        while(pointer1->add!=NULL)
                        {
                        pointer2=pointer1;
                        pointer1=pointer1->add;
                        }
                        pointer2->add=NULL;
                        curr=pointer2;
                        free(pointer1);
                        printf("Last Node DELETED !");
                        break;
                    }
                    else if(choice_char=='B')
                    {
                        pointer1=root;
                        pointer2=pointer1->add;
                        root=pointer2;
                        free(pointer1);
                        printf("First Node DELETED !");
                        break;
                    }
                    else if(choice_char=='C')
                    {
                        printf("What will be the reference :\n A. Mark the given postion by Node number. \n B. Mark the given position by data\n");
                        scanf(" %c",&choice_char);
                        if(choice_char=='A')
                            {
                                int node_num;
                                printf("Enter the node number : ");
                                scanf("%d",&node_num);
                                pointer1=root;
                                for(int i=0;i<node_num-2;i++)
                                {
                                  pointer1=pointer1->add;
                                }
                                pointer2=pointer1->add;
                                pointer3=pointer2->add;
                                pointer1->add=pointer3;
                                free(pointer2);
                                break;
                            }
                            else if(choice_char=='B')
                            {
                                printf("Enter the data to be searched for : ");
                                scanf("%d",&data);
                                pointer1=root;
                                while(pointer1!=NULL)
                                {
                                    if(pointer1->data==data)
                                    break;
                                    else
                                    {
                                    pointer2=pointer1;
                                    pointer1=pointer1->add;
                                    }
                                }
                                if(pointer1->data!=data)
                                {
                                    printf("No such data value found . ");
                                }
                                else
                                {
                                    pointer3=pointer1->add;
                                    pointer2->add=pointer3;
                                    free(pointer1);
                                }           
                        }
                    }
                    else 
                    {
                        printf("INVALID CHOICE :-( , Try Again !!");
                    }
                    break;
                    
            case 3 :
                    traverse();
                    break;
            case 4 :
                    exit (0);
        }
    }
}
return 0;
}
