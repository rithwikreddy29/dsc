#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define size 100
int stack[81];
int tos = -1;
void push(int elem)
{
	stack[++tos] = elem;
}
int pop()
{
	return stack[tos--];
}
bool isOperator(char token)
{
	switch(token)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '%': return true;
         default:return false;
	}
}
 int compute(int op1,int op,int op2)
 {
  switch(op)
  {
  case '+': return op1+op2;
  case '-': return op1-op2;
  case '*': return op1*op2;
  case '/': if(op2!=0)
                 return op1/op2;
  }
 }
int evaluate(char postfix[])
{
   int i,op1,op,op2,res;
   char token;
   for(i=0;postfix[i]!='\0';i++)
   {
   // read the token
   token=postfix[i];
   //token may bne a operator
   if (true== isOperator(token))
   {
    op2=pop();
    op1=pop();
    res=compute(op1,token,op2);
    push(res);
   }
    else 
    //token may be a operand
    push(token-'0');
   }
   res=pop();
   return res;                   
}
int main(void)
{ 
        int res;
	char postfix[81];
	printf("Enter the postfix expression : ");
	scanf("%s", postfix);
	res=evaluate(postfix);
	printf("postfix is : %d\n",res);
	return 0;
}  
