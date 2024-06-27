Write a C program to implement the following operations on Singly Linked List.
(i)	Polynomial Addition
(ii)	Polynomial Subtraction
(iii)	Polynomial Multiplication





Aim:

To write a C program to implement the following operations on singly linked list 
(i)	Polynomial Addition
(ii)	Polynomial Subtraction
(iii)	Polynomial Multiplication 

Algorithm:

1.	Start
2.	Define structure 
3.	Create term functions
4.	Insert term into the polynomial and add subtract and multiplication these polynomial and display it.
5.	End


 
Program:

#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int pow;
    struct node *next;
};

struct node* create_node()
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    if(p!=NULL)
    { 
       printf("Enter the coefficient:-");
       scanf("%d",&p->coeff);
      printf("Enter the power of x:-");
      scanf("%d",&p->pow);
      p->next=NULL;
    }
    return p;
}

struct node* create_list(int n)
{
    struct node *temp, *L1,*new;
    L1 = (struct node*)malloc(sizeof(struct node));
    temp =L1;
    while(n--)
    { 
        new = create_node();
        new->next = NULL;
 
        temp->next = new;
        temp = new; 
     }
     temp->next=NULL;
     return L1;
}

void display(struct node *L)
 {
    struct node *p;
    p= L->next;
    while(p!=NULL)
    {
       printf("%dx^",p->coeff);
       printf("%d",p->pow);
       if(p->next!=NULL)
       {
        printf("+");
       }
       p = p->next;
    }
    printf("\n");
 }

struct node* addition(struct node *L1,struct node *L2)
 {
    struct node *p1,*p2,*new, *L3,*temp;
   
    L3 = (struct node*)malloc(sizeof(struct node));
    L3->next=NULL;
    temp = L3;
    p1=L1->next;
    p2 = L2->next;
 
    while(p1!=NULL && p2!=NULL )
    {
         if(p1->pow == p2->pow)
         {
             new = (struct node*)malloc(sizeof(struct node));
             new->coeff = p1->coeff+p2->coeff;
             new->pow = p1->pow;
             p1 = p1->next;
             p2 = p2->next;
         }
         else if(p1->pow > p2->pow)
         { 
             new = (struct node*)malloc(sizeof(struct node));
             new->coeff = p1->coeff;
             new->pow = p1->pow;
             p1 = p1->next;
         }
         else if(p1->pow < p2->pow)
         { 
             new = (struct node*)malloc(sizeof(struct node));
             new->coeff = p2->coeff;
             new->pow = p2->pow;
             p2 = p2->next;
         }
         temp->next = new;
         new->next= NULL;
         temp = temp->next;
    }

    if(p1==NULL)
    {
        while(p2!=NULL)
        {
            new = (struct node*)malloc(sizeof(struct node));
            new->coeff = p2->coeff;

         new->pow = p2->pow;
         temp->next = new;
         new->next= NULL;
         temp = temp->next;
          p2 = p2->next;
        }
    }
     else if(p2==NULL)
    {
        while(p1!=NULL)
        {
            new = (struct node*)malloc(sizeof(struct node));
            new->coeff = p1->coeff;
         new->pow = p1->pow;
         temp->next = new;
         new->next= NULL;
         temp = temp->next;
          p1 = p1->next;
        }
    }  
    return L3;
 }

struct node* subtraction(struct node *L1,struct node *L2)
 {
    struct node *p1,*p2,*new, *L3,*temp;
   
    L3 = (struct node*)malloc(sizeof(struct node));
    L3->next=NULL;
    temp = L3;
    p1=L1->next;
    p2 = L2->next;
 
    while(p1!=NULL && p2!=NULL )
    {
      if(p1->pow == p2->pow)
     {
        new = (struct node*)malloc(sizeof(struct node));
         new->coeff = p1->coeff - p2->coeff;
         new->pow = p1->pow;
         p1 = p1->next;
          p2 = p2->next;
         }
     else if(p1->pow > p2->pow)
     {  new = (struct node*)malloc(sizeof(struct node));
        new->coeff = p1->coeff;
         new->pow = p1->pow;
          p1 = p1->next;
         }
     else if(p1->pow < p2->pow)
     {  new = (struct node*)malloc(sizeof(struct node));
        new->coeff = -p2->coeff;
         new->pow = p2->pow;
          p2 = p2->next;
     }
         temp->next = new;
         new->next= NULL;
         temp = temp->next;
    }

    if(p1==NULL)
    {
        while(p2!=NULL)
        {
            new = (struct node*)malloc(sizeof(struct node));
            new->coeff = p2->coeff;
         new->pow = p2->pow;
 
         temp->next = new;
         new->next= NULL;
         temp = temp->next;
          p2 = p2->next;
        }
    }
     else if(p2==NULL)
    {
        while(p1!=NULL)
        {
            new = (struct node*)malloc(sizeof(struct node));
            new->coeff = p1->coeff;
         new->pow = p1->pow;
         temp->next = new;
         new->next= NULL;
         temp = temp->next;
          p1 = p1->next;
        }
    }
    return L3;
 }

struct node* multiplication(struct node *L1,struct node *L2)
 {
    struct node *p1,*p2,*new, *L3,*temp;
   
    L3 = (struct node*)malloc(sizeof(struct node));
    L3->next=NULL;
    temp = L3;
    p1=L1->next;
    p2 = L2->next;
    while(p1!=NULL)
    {  
        p2 = L2->next;
 
        while(p2!=NULL)
        { 
         new = (struct node*)malloc(sizeof(struct node));
         new->coeff = p2->coeff*p1->coeff;
         new->pow = p1->pow+p2->pow;
         temp->next = new;
         new->next= NULL;
         temp = temp->next;
         p2 =p2->next;
        }
        p1 = p1->next;
    }    
    return L3;
 }

struct node* add(struct node *l3)
{
    struct node *temp,*p,*ref;
    temp = l3->next;
    while(temp!=NULL)
    {
        p = temp->next;
        ref =temp;
        while(p!=NULL)
        {
            if(temp->pow==p->pow)
            {
                temp->coeff = temp->coeff + p->coeff;
                ref->next = p->next;
                free(p);
               p=ref->next;
           }
 
           else
           {
               ref=ref->next;
               p=p->next;
           }
     }
        temp = temp->next;
    }
    return l3;
}

int main()
{
    struct node *l1 , *l2,*la,*ls,*lm;
    int n;

    printf("Enter the polynomials in Descending order only");
    printf("\nNO. of terms in polynomial 1:-");
    scanf("%d",&n);
    l1 = create_list(n);

    printf("\nNO. of terms in polynomial 2:-");
    scanf("%d",&n);
    l2 = create_list(n);
    
    printf("L1=");
    display(l1);
    printf("L2=");
    display(l2);

    printf("\nThe Sum of the two polynomial is=");
    la=addition(l1,l2);
    display(la);
 

    printf("The difference of the two polynomial is=");
    ls=subtraction(l1,l2);
    display(ls);

    printf("The product of the two polynomial is=");
    lm=multiplication(l1,l2);
    lm=add(lm);
    display(lm);   
}
 
Output:

Enter the polynomials in Descending order only
NO. of terms in polynomial 1: 3
Enter the coefficient:- 2
Enter the power of x:- 3
Enter the coefficient:- 3
Enter the power of x:- 2
Enter the coefficient:- 4
Enter the power of x:- 1

NO. of terms in polynomial 2: 4
Enter the coefficient:- 1
Enter the power of x:- 4
Enter the coefficient:- 2
Enter the power of x:- 3
Enter the coefficient:- 5
Enter the power of x:- 2
Enter the coefficient:- 1
Enter the power of x:- 1

L1=2x^3+3x^2+4x^1
L2=1x^4+2x^3+5x^2+1x^1

The Sum of the two polynomial is=1x^4+4x^3+8x^2+5x^1
The difference of the two polynomial is=-1x^4+0x^3+-2x^2+3x^1
The product of the two polynomial is=2x^7+7x^6+20x^5+25x^4+23x^3+4x^2

