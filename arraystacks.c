//stack program by using arraylist
//header files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct StackADT{
  float *list;
  int tos;//top of stack
  int capacity;
};

typedef struct StackADT Stack;
Stack* create(int );
bool push(Stack*,float);
bool pop(Stack*,float*);
bool peep(Stack*,float*);
void display(Stack*);
void destroy(Stack*);
//main function definition/
int main(void)
{
  float elem;
  int choice;
  bool res;
  Stack *ps;//pointer to stack
  //create memory for the stack
  ps = create(10);
  do{
      printf("\n1.push\n2.pop\n3.peek\n4.display\n5.destroy\n");
      printf("Enter your choice : ");
      scanf(" %d",&choice);
      switch(choice){
           case 1:
                  printf("Enter the element : ");
                  scanf(" %f",&elem);
                  res = push(ps,elem);
                  if(false == res)
                     printf("list may be full\n");
                  else
                     printf("%f element is pushed\n",elem);
                  break;
           case 2:
                  res = pop(ps,&elem);
                  if(false == res)
                     printf("list may be empty\n");
                  else
                     printf("%f is popped\n",elem);
                   break;
           case 3:
                 res = peep(ps,&elem);
                 if(false == res)
                   printf("no elements found show \n");
                 else
                   printf("the upper most element is %f\n",elem);
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
//function defination for create/
 Stack* create(int cap){
   Stack *pthis;
   //create memory for whole
   pthis = (Stack*)malloc(sizeof(Stack));
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
   //intialize the stack members 
   pthis -> capacity = cap;
   pthis -> tos = -1;
   //return the pointer
   return pthis;
 }
//function definition for push/
bool push(Stack *pthis,float elem){
  //increament the tos
  pthis -> tos ++;
  //place the element in the position of tos
  pthis -> list[pthis -> tos] = elem;
  return true;
}
//function definition for pop/
bool pop(Stack *pthis,float *pDel){
  //check for the emptyness
   if(-1 == pthis -> tos )
      return false;
  //store the last value to display it
  *pDel = pthis -> list[pthis -> tos];
  //decreament the tos
  pthis -> tos --;
  return true;
}  
bool peep(Stack *pthis,float *pDel){
  //check for the emptyness
   if(-1 == pthis -> tos )
      return false;
  //store the last value to display it
  *pDel = pthis -> list[pthis -> tos];
  return true;
}
//function definition for display/
void display(Stack *pthis){
  int i;
  //print from the top to feel like stack
  for(i = pthis -> tos;i >= 0;i --)
     printf("stack[%d] = %f\n",i,pthis -> list[i]);
}
//function definition for destroy/
void destroy(Stack *pthis){
  //destory the parts first 
  free(pthis -> list);
  //destroy the whole
   free(pthis);
   exit(1);
}
