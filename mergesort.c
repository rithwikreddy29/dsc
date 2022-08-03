#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void readlist(int[],int);
void printlist(int[],int);
void mergesort(int[],int,int);
void merge(int[],int,int,int);
int main(void)
{
 int list[100];
 //input
 readlist(list,8);
 printf("\n before sorting the list is :");
 printlist(list,8);
 mergesort(list,0,7)
 printf("after sorting the list is : \n");
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
void mergesort(int list[],int low ,int high)
{
 int mid;
 if(low<high)
 {
   mid=(low+high)/2;
   mergesort(list,low,mid);
   mergesort(list,mid+1,high);
   merge(list,low,mid,high);
      }
    }
void merge(int list[],int low,int mid,int high)
{
 int i,j,k;
 int *temp=NULL;
 temp=(int*)malloc(sizeof(int)*(high-low+1));
 i=low;
 j=mid+1;
 k=0;
 while((i<=mid)&&(j<=high))
      {
        if(list[i]<list[j])
             temp[k++]=list[i++];
       else         
             temp[k++]=list[j++];
      }   
 while (j<=high)
         temp[k++]=list[j++];
  //second list
 while (i<=high)
         temp[k++]=list[i++];  
  //copy all merged elem
  for(k=0,i=low;k<(high-low+1);k++,i++)
         list[i]=temp[k];
      free(temp);                      
} 
 
     
     
     
     
     
     
     
     
     
     
     
     
     
     
