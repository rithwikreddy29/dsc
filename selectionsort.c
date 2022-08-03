#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void readlist(int[],int);
void printlist(int[],int);
void exchange(int *,int *);
int findmaxindex(int[],int);
void SelectionSort(int[],int);
int main(void)
{
 int list[100];
 //input
 readlist(list,8);
 printf(" before swapping : \n");
 printlist(list,8);
 //process
 SelectionSort(list,8);
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
     printf("%d",list[i]);
 printf("\n");
 return ;
}  
void exchange(int *pa,int *pb)
{
 int temp;
      temp=*pa;
      *pa=*pb;
       *pb=temp; 
 return ;
}  
int findmaxindex(int list[],int size)
{
 int i,maxindex;
 maxindex=0;
  for(i=1;i<=size;i++)
  {
   if(list[maxindex]<list[i])
    maxindex=i;
  }
  return maxindex;
 }   
void SelectionSort(int list[],int size)
{
 int pass,maxindex;
 for(pass=1;pass<size;pass++)
 {
  maxindex=findmaxindex(list,size-pass);
  exchange(&list[maxindex],&list[size-pass]);
 }
 return ;
}
















      
   
