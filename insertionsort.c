#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void readlist(int[],int);
void printlist(int[],int);
void insertionSort(int[],int);
void insert(int[],int,int);
int main(void)
{
 int list[100];
 //input
 readlist(list,8);
 printf(" before swapping : \n");
 printlist(list,8);
 //process
 insertionSort(list,8);
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
     printf("%d  ",list[i]);
 printf("\n");
 return ;
}  
void insertionSort(int list[],int size)
{
 int pass,i,elem;
 for(pass=1;pass<size;pass++)
 {
  elem=list[pass];
  insert(list,pass,elem);
 }
 return ;
}
void insert(int list[],int size,int elem)
{
 int pass,i;
 for(i=size-1;(i>=0)&&(elem<list[i]);i--)
 {
  list[i+1]=list[i];
 } 
 list[i+1]=elem;
}
  
