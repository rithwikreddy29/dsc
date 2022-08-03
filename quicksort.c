#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void readlist(int[],int);
void printlist(int[],int);
int partition(int[],int,int);
void quicksort(int[],int,int);
int main(void)
{
 int list[100];
 //input
 readlist(list,8);
 printf(" before swapping : \n");
 printlist(list,8);
 //process
 quicksort(list,0,7);
 //output
 printf("after swapping : \n");
 printlist(list,8);
 return 0;
}
void readlist(int list[],int size)
{
 int i;
 printf("enter %d elem \n",size);
 for(i=0;i<size;i++)
     scanf("%d",&list[i]);
 return ;
 }
void printlist(int list[],int size)
{
 int i;
 for(i=0;i<size;i++)
     printf("%d ",list[i]);
 printf("\n");
 return ;
}  
int partition(int list[],int low,int high)
{
 int i,j,k;
 int pivot,temp;
 i=low;
 j=high;
 pivot=list[low];
 while(i<j)
 {
  while(list[i]<=pivot)
  i++;
  while(list[j]<=pivot)
  j--;
  if(i<j)
  {
   temp=list[i];
   list[i]=list[j];
   list[i]=temp;
  }
   else 
    break;
  }
  list[low]=list[j];
  list[j]=pivot;  
 return j;
}
void quicksort(int list[],int low,int high)
{
 int j;
 if(low<high)
 {
   j=partition(list,low,high);
   quicksort(list,low,j-1);
   quicksort(list,j+1,high);
 }
 else
     return ;
}     
