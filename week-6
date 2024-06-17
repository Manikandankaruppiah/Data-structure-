Write a C program to evaluate Arithmetic expression using stack. 

Aim:
To evaluate arithmetic expression using stack

Algorithm:

1.Start

2.Define an array stack to hold operands, and a character array str to store the input expression.

3.Define a function push to push an operand onto the stack.

4.Define a function pop to pop an operand from the stack.

5.Define a function evaluate to perform arithmetic operations on two operands.

6.In the main function:
•	Declare variables temp and i.
•	Prompt the user to enter an equation.
•	Read the equation into the str array.
•	Iterate through each character in str:
•	If the character is a digit, update temp by multiplying its current value by 10 and adding the digit.
•	If the character is a space, push the accumulated number temp onto the stack and reset temp to 0.
•	If the character is an operator ('+', '-', '*', '/', '%'):
•	Pop two operands (num2 and num1) from the stack.
•	Evaluate the expression (num1 op num2) using the operator and push the result onto the stack.
•	Increment i to skip the next character (since it's an operator).
•	Check if the last character in the expression is a digit or if there's only one element left in the stack. If not, print "Invalid expression" and exit.
•	Print the final result, which is the only element left in the stack.
•	
7.End.
 
Program:

#include<stdio.h>
#include<stdlib.h>

int stack[30];
char str[30];
int top=-1;

void push(int num)
{
    top++;
    stack[top]=num;
}

int pop()
{
    int last=stack[top];
    top--;
    if(top!=-2)    return last;
    else
    {
        printf("Invalid expression...");
        exit(-1);
    }
}

int evaluate(int num1,int num2,char op)
{
    switch(op)
    {
        case '+':
        return num1+num2;
        break;
 
        case '-':
        return num1-num2;
        break;
        
        case '*':
        return num1*num2;
        break;
        
        case '/':
        return num1/num2;
        break;
        
        case '%':
        return num1%num2;
        break;
    }
}

void main()
{
    int temp=0,i;
    printf("Enter equation: ");
    scanf("%[^\n]s",str);
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='0'&& str[i]<='9')
        temp=temp*10+((int)(str[i]-'0'));
        
        else if(str[i]==' ')
        {
            push(temp);
            temp=0;
        }
 
        else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='%')
        {
            int num2=pop();
            int num1=pop();
            int result=evaluate(num1,num2,str[i]);
            push(result);
            i++;
        }
    }
    
    if(str[i-1]>='0'&& str[i+1]<='9' || top!=0)
    {
        printf("Invalid expression...");
        exit(-1);
    }
    
    printf("Result = %d",pop());
}






Output:

Enter equation: 5 3 * 8 -
Result = 7

