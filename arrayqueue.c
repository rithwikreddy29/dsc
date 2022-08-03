#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct QueueADT{
  float *list;
  int front,rear;
  int capacity;
};

typedef struct QueueADT Queue;
Queue* create(int cap )
 {
  Queue*pthis;
  pthis=(Queue*)malloc(sizeof(Queue));
  pthis->list=(float*)malloc(cap*sizeof(float));
  pthis->rear=-1;
  pthis->front=0; 
  pthis->capacity=cap;
  return pthis;
  } 
bool enqueue(Queue* ,float);
bool dequeue(Queue* ,float* ); 
void display(Queue*);


bool enqueue(Queue*pthis,float elem)
 {
   if(pthis->rear+1==pthis->capacity)
   return false;
   pthis->rear=pthis->rear+1;
   pthis->list[pthis->rear]=elem;
   return true;
 }  
  
bool dequeue(Queue* pthis,float* elem)
 {
   if(pthis->rear<pthis->front);
   return false;
   *elem=pthis->list[pthis->front];
   pthis->front=pthis->front+1;
   return true;
 }
 void display(Queue *pthis)
{
  int i;
  printf("queue is as follows\n");
  for(i=pthis->front; i<=pthis->rear;i++)
  {
       printf("%f\n",pthis->list[i]);   
 }
}
 int main(void)
{
  Queue*  pq  =  create(10);
  float elem;
  int ch;
  
  do{
      printf("\n1.enqueue\n2.dequeue\n3.display:  ");
      printf("\n Enter your choice : ");
      scanf(" %d",&ch);
      switch(ch){
           case 1:
                  printf("Enter the enquened: ");
                  scanf("%f",&elem);
                   
                    printf("%f is enquened\n",elem);   
                    (enqueue(pq,elem));          
                  break;
           case 2:
                  dequeue(pq,&elem);
                  printf("%f is dequeud\n",elem);              
                  break;
           case 3: display(pq);
                   break;
               
       } 
    
  }while(true);
  printf("\n");
  return 0;
}
 
 
 
 
