#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
 
 struct ArrayListADT
 {
  float*list;
  int size;
  int capacity;
 };
 typedef struct ArrayListADT ArrayList;
 ArrayList *create( int );
 bool insertBeg(ArrayList*,float);
 bool insertAt(ArrayList*,float,int);
 bool append(ArrayList*,float,int);
 bool deleteBeg(ArrayList*,float*);
 bool deleteAt(ArrayList*,float*,int);
 bool deleteEnd(ArrayList*,float*);
 void display(const ArrayList*);
 void destroy(ArrayList*);
 int main(void)
 {
  ArrayList *al;
  int choice;
  int pos;
  float elem;
  al=create(4);
 do{
    printf("\n1.insert\n2.delete\n3.display\n4.exit\n");
    printf("enter the choice=  ");
    scanf("%d",&choice);
    switch(choice)
   {
    case 1: printf("enter the elements:  ");
            scanf("%f",&elem);
            printf("enter the position:  ");
            scanf("%d",&pos);
            if(0==pos)
            {
              if(false==insertBeg(al,elem) )
                printf("list may be full\n");
                }
                else if(al -> size==pos)
                {
                 if(false==append(al,elem,pos))
                   printf("list may be full");
                 }
                 else
                 {
                 if(false==insertAt(al,elem,pos))
                   printf("list may be full");
                 }
            break;
          
      case 2: printf("enter position: ");
              scanf("%d",&pos);
              if(0==pos)
              if(true==deleteBeg(al,&elem))
              printf("%f got deleted",elem);
              else if (al->size-1==pos)
              {
              if(true==deleteEnd(al,&elem))
              printf("%f got deleted",elem);
              }
              else
              {
               if(true==deleteAt(al,&elem,pos))
               printf("%f got deleted",elem);
               }          
          
    case 3: display(al);
            break;
    case 4: destroy(al);
            return 0;
            }

 }while(true);
  printf("\n");
  return 0;
}
ArrayList *create(int cap)
 { 
  ArrayList *pthis=NULL;
  //allocate memory for whole 
  pthis=(ArrayList*)malloc(sizeof(ArrayList) );
  //initialize non pointer members
  pthis->size=0;
  pthis->capacity=cap;  
  //allocate memory for parts
  pthis->list=malloc(pthis->capacity*sizeof(float) );
  
  return pthis;
 }
  void destroy(ArrayList*pthis)
  {
   free(pthis->list);
   free(pthis);
  }  
   bool insertBeg(ArrayList*pthis,float elem)
  {
   int i;
   if(pthis->size==pthis->capacity)
    return false;
    for(i=pthis->size-1;i>=0;i--)
    pthis->list[i+1]=pthis->list[i];
    pthis->list[0]=elem;
    pthis->size++;
    return true;
    }
    bool insertAt(ArrayList*pthis,float elem ,int pos)
   {
   int i;
    if(pos<0||pos>pthis->size)
      return false ;
     if(pthis->size==pthis->capacity)
      return false ;
     for(i=pthis->size-1;i>=pos;i--)
     pthis->list[i+1]=pthis->list[i];
     pthis->list[pos]=elem;
      pthis->size++;
      return true;
      } 
    bool append(ArrayList*pthis,float elem,int pos)
    {
    if(pthis->size==pthis->capacity)
      return false ;
      pthis->list[pthis->size]=elem;
      pthis->size++;
      return true;
      }
     bool deleteBeg(ArrayList*pthis,float*pDel)
     {
     int i;
     if(0==pthis->size)
     return false;
     *pDel=pthis->list[0];
     //shift elementrange[1......size-1]
     for(i=1;i<pthis->size;i++)
     pthis->list[i-1]=pthis->list[i];
     pthis->size--;
     return true;
     }
     bool deleteAt(ArrayList*pthis,float*pDel,int pos)
     {
     int i;
     if(pos<0||pos>=pthis->size)
     return false;
     *pDel=pthis->list[pos];
     for(i=pos+i;i<pthis->size;i++)
     pthis->list[i-1]=pthis->list[i];
     pthis->size--;
     return true;
     }
     bool deleteEnd(ArrayList*pthis,float*pDel)
     {
     if(pthis->size==0)
     return false;
     *pDel=pthis->list[pthis->size-1];
     pthis->size--;
     return true;
     }
    void display (const ArrayList*pthis )  
    {
    int i;
    for(i=0;i<pthis->size;i++)
    printf("list[%d]=%f\n",i,pthis->list[i]);
    }
