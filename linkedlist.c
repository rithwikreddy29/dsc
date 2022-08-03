#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct NodeADT 
{
    int data;
    struct NodeADT* link;
};
typedef struct NodeADT Node;
struct LinkedListADT 
{
    Node* head;
};
typedef struct LinkedListADT LinkedList;
LinkedList* create(void);
Node* newNode(int);
void destroy(LinkedList*); 
bool insertBeg(LinkedList* ,int); 
void display( LinkedList*);
bool isEmpty(LinkedList *);
bool append(LinkedList* ,int);
int nodecount(LinkedList*);
bool insertAt(LinkedList* ,int, int);
bool deleteBeg(LinkedList*,int *);
bool deleteEnd (LinkedList*,int*);
bool deleteAt(LinkedList*,int *,int);
int main(void)
{
  LinkedList*ll;
  int choice,data,pos; 
  bool res;
  do {
  printf(" 1.insert\n 2.delete\n 3.display\n 4.destroy\n\n");
  printf("enter your choice:\n");
    scanf(" %d",&choice);
 
   switch(choice)
    {  
        case 1:  printf("enter the Node to insert:\n");
                 scanf(" %d",&data);
                 printf("enter the position:\n");
                 scanf(" %d",&pos);
                if(pos==0)
                   res=insertBeg(ll,data);
                else if(pos==nodecount(ll));
                  res=append(ll,data);
                else 
                    res=insertAt(ll,data,pos);
                if(res==true)
                printf(" %d insertion successfully\n",data); 
                else 
                printf("not inserted\n");
                break;
        case 2: printf("Enter node  to be deleted:\n");
                scanf(" %d",&pos);
                if(0==pos)
                  res=deleteBeg(ll,&data);
                if(count(ll)-1==pos)
                  res=deleteEnd(ll,&data);
                else
                   res=deleteAt(ll,&data,pos);              
               if(res==true)
                 printf(" %d node deleted\n",data);
               else 
                 printf("deletion failure\n");
               break;
        case 3: display(ll);
                break;
        case 4: destroy(ll); 
                return 0;
                break;
      
      default: printf("invalid choice:\n");     
    }
  } 
  while(true);
  putchar("\n");
  return 0;
}
LinkedList* create(void){
    LinkedList* pthis=NULL;
    pthis=(LinkedList*)malloc(sizeof(LinkedList));
    if(NULL==pthis)
    {
        perror("malloc");
        exit(1);
    }
    pthis->head=NULL;
    pthis->size=0;
    return pthis;
} 
Node* newNode(int data)
{
    Node *pNew=NULL;
    pNew=(Node*)malloc(sizeof(Node));
    if(NULL==pNew)
    {
        perror("malloc");
        exit(1);
    }
 pNew->link=NULL;   
 pNew->data=data;
 return pNew;
} 
void destroy(LinkedList* pthis){
  Node* pDel;    
    while(NULL!=pthis->head){
      pDel=pthis->head;
      printf("destroyed  %d node\n",pDel->data);
       pthis->head=pthis->head->link;
       free(pDel);  
    } 
     free(pthis);
       pthis=NULL;
} 
bool insertBeg(LinkedList* pthis,int data)
{   
   Node *pNew=newNode(data);
    if(NULL==pNew)
     return false; 
   pNew->link=pthis->head;
   pthis->head=pNew;   
   return true;
}
void display( LinkedList* pthis)
{
    Node* jump;
    jump=pthis->head;
    printf("linked list is as follow \n");
    while(NULL!=jump)
    {
        printf("|%d   %p|\n",jump->data,jump->link); 
        if(jump->link!=NULL)
        printf(" -> ");
       jump=jump->link;
    }
    printf("\n");
}
bool isEmpty(LinkedList* pthis)
{
  return(pthis->head==NULL)?true:false;
} 
bool append(LinkedList* pthis,int data)
{
   
   Node* ln;
  Node*pNew=newNode(data);
  if(is empty(pthis))
  {
   pthis->head=pNew;
  }
  ln=pthis->head;
  while(NULL!=ln->link)
    ln=ln->link;
 
    ln->link=pNew;
  return true;  
}
int nodecount(LinkedList* pthis)
{ 
  int count=0;
  Node* jump;
  jump=pthis->head;
  while(NULL!=jump)
  {
   count++;
   jump->link=jump;
 } 
   return count;
}
bool insertAt(LinkedList* pthis,int data,int pos)
{
  int i;
  if(pos<0 || pos>count(pthis)) 
   return false;
   Node* pNew;
 Node*pNew=newNode(data);
   Node* prev;
  prev=pthis->head;
  for(i=0;i<pos-1;i++)
   prev->link=prev;
   pNew->link=prev->link;
  if(NULL!=prev)
    prev->link=pNew;
  return true;
}
bool deleteBeg(LinkedList* pthis,int *delem)
{
  if(isEmpty(pthis)==true)
   return false; 
  Node* pDel;
  pDel=pthis->head;
  *delem=pDel->data;
  pthis->head=pDel->link;
   free(pDel);
   return true;
}
bool deleteEnd(LinkedList* pthis, int *delem){
   if(isEmpty(pthis)==true)
      return false;
   Node* lbo;
   Node* pDel;
   
   if(NULL==pthis->head->link){
    pDel=pthis->head;
    pthis->head=NULL;
    *delem=pDel->data;
    free(pDel);
    return true;
   }
   lbo=pthis->head;
   while(NULL!=lbo->link->link)
   lbo=lbo->link;
  pDel=lbo->link;
  lbo->link=NULL;
   *delem=pDel->data;
  free(pDel);
  return true;
} 
bool deleteAt(LinkedList * pthis,int *delem,int pos){
   int i;
  Node *pDel;
  Node* cursor;
 if(isEmpty(pthis)==true)
     return false;
  if(pos<0 || pos>count(pthis))
    return false;
  cursor=pthis->head;
  for(i=0;i<pos-1;i++)
    cursor=cursor->link;
    pDel=cursor->link;
  cursor->link=pDel->link;
  *delem=pDel->data;
  free(pDel);
   return true;
}  
   
