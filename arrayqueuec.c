#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct QueueADT{
  float *list;
  int rear;
  int capacity;
  int front;
};

typedef struct QueueADT Queue;
Queue* create(int );
bool enqueue(Queue*,float);
bool dequeue(Queue*,float*);
void display(Queue*);
void destroy(Queue*);
//main function definition
int main(void)
{
  float elem;
  int choice;
  bool res;
  Queue *pq;
  pq = create(5);
  do{
      printf("\n1.enqueue\n2.dequeue\n3.display\n4.destroy\n");
      printf("Enter your choice : ");
      scanf(" %d",&choice);
      switch(choice){
           case 1:
                  printf("Enter the element : ");
                  scanf(" %f",&elem);
                  res = enqueue(pq,elem);
                  if(false == res)
                     printf("Queue may be full\n");
                  else
                     printf("%f element is enqueued\n",elem);
                  break;
           case 2:
                  res = dequeue(pq,&elem);
                  if(false == res)
                     printf("queue may be empty\n");
                  else
                     printf("%f is dequeued\n",elem);
                   break;
           case 3:display(pq);
                   break;
           case 4:destroy(pq);
                   break;
           default : 
                   printf("Enter valid choice\n");
               
       } 
    
  }while(true);
  printf("\n");
  return 0;
}
//function definition for create
 Queue* create(int cap){
   Queue *pthis;
   //create memory for whole
   pthis = (Queue*)malloc(sizeof(Queue));
   //check whether the memory is allocated
   if(NULL == pthis)
   {
     perror("malloc");
     exit(1);//defence statement
   }
   //allocate memory for the parts
   pthis -> list = (float*)malloc(cap*sizeof(float));
   //check whether memory is allocated
   if(NULL == pthis -> list)
   {
     perror("malloc");
     exit(1);
   }
   //intialize the queue members 
   pthis -> capacity = cap;
   pthis -> rear = -1;
   pthis -> front = 0;
   //return the pointer
   return pthis;
 }
//function definition for enqueue
bool enqueue(Queue *pthis,float elem){
  //check whether queue is full
  if(pthis -> rear +1  == pthis -> capacity)
    return false;
  //increament the rear
  pthis -> rear++;
  //insert elem at rearth position 
  pthis -> list[pthis -> rear] = elem;
  return true;
}
//function definition for dequeue
 bool dequeue(Queue *pthis,float *pDel){
  //check for the emptyness
   if(-1 == pthis -> rear ||pthis -> front > pthis -> rear )
      return false;
  //store the last value to display it
  *pDel = pthis -> list[pthis -> front];
  pthis -> front ++;
  return true;
}
//function definition for display
void display(Queue *pthis){
  int i;
  for(i = pthis -> front;i <= pthis -> rear;i ++)
     printf("%f\n",i,pthis -> list[i]);
}
//function definition for destroy
void destroy(Queue* pthis){
  //destory the parts first 
  free(pthis -> list);
  //destroy the whole
   free(pthis);
   exit(1);
}
