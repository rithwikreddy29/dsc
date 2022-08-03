#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Nodetype
{
    int data;
    struct Nodetype* link;
};
typedef struct Nodetype Node;

struct StackADT
{
    Node* tos;
};
typedef struct StackADT Stack;

Node* newNode(char data)
{
    Node* pNew;
    //allocate memory
    pNew = (Node*)malloc(sizeof(Node));
    //assign values
    pNew->data = data;
    pNew->link = NULL;
    return pNew;
}

Stack* create(void)
{
    Stack* pthis;
    //allocate memory
    pthis = (Stack*)malloc(sizeof(Stack));
    //initialize members
    pthis->tos = NULL;
    return pthis; 
}

bool push(Stack*pthis,int data)
{
    Node* pNew = newNode(data);
    if (pNew==NULL)
        return false;
    //attach new node to existing node
    pNew->link = pthis->tos;
    //new node becomes top of stack
    pthis->tos = pNew;
    return true;
}

bool pop(Stack*pthis,int *data)
{
    Node* pDel;
    //validate if stack is empty
    if(pthis->tos == NULL)
      return false;
    //logical deletion: next ele of tos becomes tos
    //copying elem into pass by ref
    pDel = pthis->tos;
    *data = pDel->data;
    pthis->tos = pthis->tos->link;
    //physical deletion
    free(pDel);
    return true;
}

bool peep(Stack*pthis,int *data)
{
    Node* pDel;
    //validate if stack is empty
    if(pthis->tos == NULL)
      return false;
    //copying elem into pass by ref
    pDel = pthis->tos;
    *data = pDel->data;
    return true;
}

void display(Stack*  pthis)
{
    Node * cursor;
    printf("Stack is as follows\n");
    for(cursor = pthis->tos;cursor!= NULL;cursor= cursor->link)
       printf("%d\n",cursor->data);
}

void destroy(Stack* pthis)
{
    //free parts
    free(pthis->tos);
    //free whole
    free(pthis);
}
int main()
{
    bool res;
    int ele,choice;
    Stack* ps = create();
    
    do{
      printf("\n1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
      printf("Enter your choice : ");
      scanf(" %d",&choice);
      switch(choice){
           case 1:
                  printf("Enter the element : ");
                  scanf(" %d",&ele);
                  res = push(ps,ele);
                  if(false == res)
                     printf("list may be full\n");
                  else
                     printf("%d element is pushed\n",ele);
                  break;
           case 2:
                  res = pop(ps,&ele);
                  if(false == res)
                     printf("list may be empty\n");
                  else
                     printf("%d is popped\n",ele);
                   break;
           case 3:
                 res = peep(ps,&ele);
                 if(false == res)
                   printf("no elements found show \n");
                 else
                   printf("the upper most element is %d\n",ele);
                  break;
           case 4:display(ps);
                   break;
           case 5:destroy(ps);
                   break;
           default : 
                   printf("Enter valid choice\n");
               
       } 
    
  }while(true);
  printf("\n");
  return 0;
}
