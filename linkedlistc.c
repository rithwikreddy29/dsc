#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct NodeADT
{
	int data;
	struct NodeADT * link;
};
typedef struct NodeADT Node;

struct LinkedListADT
{
	Node *  head;
	int size;
};
typedef struct LinkedListADT LinkedList;

LinkedList * create(void);
Node *NewNode(int);
void display(LinkedList *);
bool insertBeg(LinkedList *,int);
bool append(LinkedList *,int);
bool insertAt(LinkedList *,int,int);
void destroy(LinkedList *);
int nodeCount(LinkedList *);
bool isEmpty(LinkedList *);
bool deleteBeg(LinkedList *,int * );
bool deleteEnd(LinkedList *, int *);
bool deleteAt(LinkedList *, int *,int);

int main(void)
{
	LinkedList * ll;
	int pos,choice,data; 
	bool res;
	ll=create();
	do
	{
		printf("1.insert \t 2.delete \t 3.display \t 4.destroy \n");
		printf("enter your choice:");
		scanf("%d",&choice);
  		switch(choice)
  		{
  			case 1://insertion
  				printf("enter data of node :");
  				scanf("%d",&data);
  				printf("enter the position: ");
  				scanf("%d",&pos);
  				if(0==pos)
  					res=insertBeg(ll,data);
  				else if(nodeCount(ll)==pos)
  					res=append(ll,data);
  				else
  					res=insertAt(ll,data,pos);
  				if(true==res)
  					printf("%d insertion is sucessful \n",data);
  				else
  					printf("insertion is failed");
  				break;
  			case 2://deletion
  				printf("enter the position:");
  				scanf("%d",&pos);
  				if(pos==0)
  					res=deleteBeg(ll,&data);
  				else if(nodeCount(ll)-1)
  					res=deleteEnd(ll,&data);
  				else
  					res=deleteAt(ll,&data,pos);
  				if(true==res)
  					printf("%d is deleted sucessfully \n",data);
  				else
  					printf("deletion is failed\n");
  				break;	
  			
  			case 3://display the nodes
  				display(ll);
  				break;
  			case 4://destroy
  				destroy(ll);
  				return 0;
  		}			
	}
	while(true);
		printf("\n");
		return 0;
}
LinkedList * create(void)
{
	LinkedList *pthis=NULL;
	//dynamic memory allocation
	pthis=(LinkedList*)malloc(sizeof(LinkedList));
	if(NULL==pthis)
	{
		perror("malloc");
		exit(1);
	}
	//memory allocation was sucessfull
	pthis->head=NULL;//fill the fields of pthis
	pthis->size=0;
	//return pthis
	return pthis;	
}
Node *newNode(int data)
{
	Node *pNew=NULL;
	//dynamic memory allocation of pthis
	pNew=(Node*)malloc(sizeof (Node));
	if(NULL==pNew)
	{
		//when malloc fails to allocate memory
		perror("malloc");
		exit(1);
	}
	//memory allocation was sucessfull
	pNew->data=data;//fill the fields of pNew 
	pNew->link=NULL;
	//finally return
	return pNew;
}
int nodeCount(LinkedList *pthis)
{
	Node *jump;
	int count=0;
	jump=pthis->head;//let jump point to head
	while(NULL!=jump)
	{
		count++;//increment the count until the jump becomes NULL
		jump=jump->link;
	}
	return count;
} 
bool isEmpty(LinkedList *pthis)
{
	return(pthis->head==NULL)?true:false;

}
void display(LinkedList *pthis)
{
	Node *jump;
	jump=pthis->head;//let jump points to head
	while(NULL!=jump)
	{
		printf("|%d %p|",jump->data,jump->link);
		if(jump->link!=NULL)
			printf("->");
			jump=jump->link;//let jump points to its link
	}
	printf("\n");
}
bool insertBeg(LinkedList *pthis,int data)
{
	Node *pNew=newNode(data);//creat a new node
	if(NULL==pNew)
		return false;
	pNew->link=pthis->head;//assign head into new nodes link
	pthis->head=pNew;//copy new node
	return true;
}
bool append(LinkedList *pthis,int data)
{
	Node *lp;
	Node *pNew=newNode(data);
	if(isEmpty(pthis))
	{
		//when list is empty
		pthis->head=pNew;//assign new node into head
	}
	//assign new node  into head
	lp=pthis->head;
	while(NULL!=lp->link)
		lp=lp->link;
	lp->link=pNew;	
	return true;
}
bool insertAt(LinkedList * pthis,int data,int pos)
{
	int i;
	if(pos<0 || pos>nodeCount(pthis)) //variable for position
		return false;
	Node * pNew=newNode(data); //creating anew node
	Node * prev;
	prev=pthis->head;//let prev points to head
	for(i=0;i<pos-1;i++)
		prev=prev->link;// let prev points to head
	pNew->link=prev->link;//assign prev's link to pNew's link
	if(NULL!=prev)
		prev->link = pNew ;//finally copy pnew into prev's link part
	return true;
	
}
bool deleteBeg(LinkedList *pthis,int *pelem)
{
	//validate for emptyness
	if(isEmpty(pthis))
		return false;
	Node *pDel;
	pDel = pthis->head;// make pDel to head 
	*pelem = pDel->data;//copy the data
	pthis->head = pDel->link;
	free(pDel);
	return true;//physical deletion
}
bool deleteEnd(LinkedList *pthis, int *pelem )
{
	//validate the emptyness of list
	if(isEmpty(pthis))
		return false;
	Node *pDel,*lbo;//last but one = lbo
	if(NULL==pthis->head->link)
	{
		// when there is a single node	
		pDel=pthis->head;
		pthis->head=NULL;
		*pelem=pDel->data;
		free(pDel); //physical deletion
		return true;
	}
	lbo=pthis->head;//make last but one pointer points to head
	while(NULL!=lbo->link->link)
		lbo=lbo->link;
	pDel=lbo->link;
	*pelem=pDel->data;
	free(pDel);//physical deletion
	return true;
}
bool deleteAt(LinkedList * pthis, int *pelem,int pos)
{
	Node *pDel,*cursor;
	int i;
	//validate the emptyness of list
	if(isEmpty(pthis))
		return false;
	if(pos<0 || pos>=nodeCount(pthis))
		return false;
	cursor=pthis->head;
	for(i=0;i<pos-1;i++)
		cursor=cursor->link;
	pDel=cursor->link;//logical deletion
	*pelem=pDel->data;
	cursor->link=pDel->link;
	free(pDel);	//physical deletion
	return true;
	
}
void destroy(LinkedList *pthis)
{
	Node *pDel;
	//release memory for all nodes that were created
	while(NULL!=pthis->head)
	{
		pDel=pthis->head;//logical deletion
		pthis->head=pthis->head->link;
		free(pDel);//physical deletion
	}
	free(pthis);//deallocate the memory that was allocated for Adt
	pthis=NULL;
}


