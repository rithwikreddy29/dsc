#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct nodeType{
  float data;
  struct nodeType *link;
};
typedef struct nodeType Node;
struct QueueADT{
  Node *rear;
  Node *front;
};
typedef struct QueueADT Queue;
Queue* create();
Node* newNode(float);
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
  Queue *pq;//pointer to queue
  //create memory for the queue
  pq = create();
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
                     printf("queue may be full\n");
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
//create function definition
Queue* create(void){
  Queue *pthis = NULL;
  //create memory for the whole
  pthis = (Queue*)malloc(sizeof(Queue));
  if(pthis == NULL)
  {
    perror("malloc");
    exit(1);
  }
  //initialize queue members 
  pthis -> rear = NULL;
  pthis -> front = NULL;
  return pthis;
}
Node* newNode(float data)
{
  Node *pNew;
  //create memory for the node
  pNew = (Node*)malloc(sizeof(Node));
  //fill the data part and link part
  pNew -> data = data;
  pNew -> link = NULL;
  return pNew;
}
bool enqueue(Queue* pthis ,float data)
{
  Node *pNew ;
  //create a node
  pNew = newNode(data);
  if(pthis -> front == NULL){
    pthis -> rear = pthis -> front = pNew;
    return true;
  }
 //add the node after the rear
  pthis -> rear -> link= pNew;
  //now new node is the rear
  pthis -> rear = pNew;
  return true;
}
bool dequeue(Queue* pthis ,float* elem)
{
  Node *pDel;
  if(pthis -> front == NULL){
    return false;
  }
  //condition for single node
  //if(pthis -> )
  //store the node address
  pDel = pthis -> front;
  //shift the front to the next node
  pthis -> front = pDel -> link;
  //store the deleted nodes data part
  *elem = pDel -> data;
  //physical deletion 
  free(pDel);
  return true;
}
void display(Queue *pthis){
  Node *jump = pthis -> front;
  //jump from each node and print
  while(jump != NULL){
    //no need to print the address part 
    printf("|%f %p|\n", jump -> data,jump -> link);
    jump = jump -> link;
   }
}
void destroy(Queue *pthis){
    float x;
    //calling each node and deleting
    while( true == dequeue(pthis,&x));
         free(pthis);
    //exit from the program
    exit(1);
}
