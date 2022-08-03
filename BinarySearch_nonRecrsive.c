#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void readList(int list[],int size)
{
  int i;
  printf("Enter %d elements : ",size);
  for(i=0; i<size; i++)
  {
    scanf("%d",&list[i]);
  }
  return;
}
void printList(int list[], int size)
{
  int i;
 
  for(i=0; i<size; i++)
  {
    printf(" %d",list[i]);
    
  }
  printf("\n"); 
  return;
}

int BinarySearchNonRecrsive(int list[],int size,int key)
{ 
 int low,mid,high;
 low=0;
 high=size-1;
 printf("enetr the element to search : ");
 scanf("%d",&key);
 while(low<=high)
  { 
   mid=(high+low)/2;
   if(key==list[mid])
        return mid;
   else if(key<list[mid])
         return (mid-1)/2;
   else 
         return (mid+1)/2;     
        
  }
 return -1;
 }
int main(void)
{
 int list[100],key,res,i;
	//intput
	readList(list,5);
	printf("Enter the list of elements: ");
	printList(list,5);
	//processing
	res=BinarySearchNonRecrsive(list,5,key);
	if(res==-1)
	  printf("Element is not found\n");
	else  
	printf("key is at  position %d ",res);
	return 0;

}

