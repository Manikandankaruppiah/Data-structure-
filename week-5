Write a C program to perform infix to postfix conversion using stack.

Aim:
To perform infix to postfix conversion using stack.

Algorithm:

1. Start 

2. Define a structure for the Node with character data and a pointer to the next node.

3. Define a function to determine the priority of operators. 

4. Define a function to push a symbol onto the stack. 

5. Define a function to pop a symbol from the stack. - Check if the stack is empty. If so, print     "Stack Underflow" and exit. 

6. Define a function to peek at the top symbol in the stack. - If the stack is empty, return null character '\0'. 

7. Define a function to display the stack. - If the stack is empty, print "The stack is empty". 

8. Define a function to check the precedence and process operators accordingly.

9. In the main function:
a.	Define variables for input string, symbol, and a stack. - Initialize the stack as NULL.
b.	Prompt the user to enter an expression. - Read the expression from the user.
c.	Iterate through each character in the expression:
i.	If it's an alphabet character, print it
ii.	If it's an operator, call the check_precedence function.
iii.	If it's a space, continue to the next character.
iv.	If it's an opening parenthesis '(', push it onto the stack.
v.	If it's a closing parenthesis ')', pop and print symbols from the stack until an opening parenthesis is encountered.
vi.	If it's any other character, print "Invalid expression" and break the loop.
d.	After the loop, pop and print any remaining symbols from the stack. 

10. End.




Program:

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char sign;
    struct Node* next;
};

int priority(char sym)
{
    if(sym=='*'||sym=='/'||sym=='%')
    return 2;
    else if(sym=='+'||sym=='-')
    return 1;
    else
    return 0;
}

void push(struct Node* L,char sym)
{
    struct Node*n = (struct Node*) malloc(sizeof(struct Node));
    if(n!=NULL)
    {
        n->sign=sym;
        if(L->next!=NULL)
        {
            n->next=L->next;
            L->next=n;
        }
 
        else
        L->next=n;
    }
}

void pop(struct Node* L)
{
    if(L->next==NULL)
    printf("\n---Stack Underflow---\n");
    else
    {  
        struct Node* temp=L->next;
        L->next = L->next->next;
        free(temp);
    }
}

char peek(struct Node* L)
{
    if(L->next==NULL)
    return '\0';
    else
    return L->next->sign;
}

void display(struct Node* L)
{
    if(L->next==NULL)
    printf("\nThe stack is empty\n");
    else
    {
        struct Node* temp=L->next;
 
        while(temp!=NULL)
        {
            printf(" | %c |\n",temp->sign);
            temp=temp->next;
        }
    }
}

void check_precedence(struct Node*L,char in_exp)
{
    char in_stack=peek(L);
   
    if(priority(in_stack) >= priority(in_exp))
    {
        printf("%c",in_stack);
        pop(L);
        check_precedence(L,in_exp);
    }
   
    else
    {
        push(L,in_exp);
    }
}

int main() {
    char str[100],sym;
    struct Node list;
    list.next=NULL;
    printf("Enter expression containing lowercase alphabets and operators (+,-,*,/,%)\n");
    scanf("%[^\n]s",str);
 
    for(int i=0;str[i]!='\0';i++)
    {
        if((str[i]>='a'&& str[i]<='z')||(str[i]>='A' && str[i]<='Z'))
        {
            printf("%c",str[i]);
        }
       
        else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
        {
            check_precedence(&list,str[i]);
        }
       
        else if(str[i]==' ')
        continue;
       
        else if(str[i]=='(')
        push(&list,str[i]);
       
        else if(str[i]==')')
        {
            while(peek(&list)!='(')
            {
                printf("%c",peek(&list));
                pop(&list);
            }
            pop(&list);
        }
        else
        {
            printf("Invalid expression ");
            break;
        }
    }
   
    while(list.next)
    {
        printf("%c",peek(&list));
        pop(&list);
    }
    return 0;
}








Output:

Enter expression containing lowercase alphabets and operators (+,-,*,/,%)
a+b*c/d-e
abc*d/+e-

