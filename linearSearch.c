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

int linersearch(int list[],int size)
{ 
 int i,key;
  printf("enetr the element to search : ");
  scanf("%d",&key);
  for( i=0;i<=size-1; i++ )
  {
    if(list[i]==key)
       return i;
  }
  return -1;
}


int main(void)
{
 int list[100],key,res,i;
	//intput
	readList(list,10);
	printf("Enter the list of elements: ");
	printList(list,10);
	//processing
	res=linersearch(list,10);
	
	
	if(res==-1)
	printf("element not found");
	else
	printf("key is at position %d \n ",res);
	
	return 0;

}

