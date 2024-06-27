Write a C program to create a hash table and perform collision resolution using the following techniques.
(i)	Open addressing
(ii)	Closed Addressing
(iii)	Rehashing 


Aim:
To write a c program to implement various hashing techniques


Algorithm:
1.	Initialize Table: Create a hash table with a specified size, ensuring it meets a minimum size requirement.
2.	Determine Prime Size: Calculate the next prime number greater than or equal to the specified table size to reduce collisions.
3.	Allocate Memory: Allocate memory for the hash table and initialize its cell array.
4.	Hash Function: Implement a hash function to map keys to indices in the hash table.
5.	Find Position: Search for a position in the hash table for insertion or retrieval, handling collisions using linear probing.
6.	Insertion: Insert a key into the hash table, marking the corresponding cell as legitimate if empty.
7.	Display: Traverse the hash table and print the contents of each cell, displaying both indices and associated data.
8.	Check Fullness: Determine whether the hash table is full, preventing further insertions if all cells are legitimate.
9.	User Interaction: Allow users to choose operations such as insertion or display, ensuring appropriate responses to fullness or invalid choices.
10.	Termination: Gracefully terminate the program upon user request, indicating the end of operations.
 
Program: (Linear Probing)

#include <stdio.h>
#include<stdlib.h>
#define MINSIZE 7
typedef int index;
typedef index position;
typedef struct hash_entry cell;
typedef struct H_table* Hashtable;
enum entry { Legitimate, Empty, Deleted };

struct hash_entry
{
    int data;
    enum entry info;
};

struct H_table
{
    int table_size;
    cell* cell_array;
};

 
int next_prime(int table_size)
{
    int i=table_size,f;
    while(1)
    {
        f=1;
        for(int j=2;j<i;j++)
        {
            if(i%j==0)
            {
                f=0;
                break;
            }
        }
        if(f==1)
        return i;
        i++;
    }
}
index Hash(int key,int table_size)
{
    return key % table_size;
}
 
Hashtable Create_table(int table_size)
{
    Hashtable H;
    if(table_size < MINSIZE)
    {
        printf("Table size too small");
        return NULL;
    }
    H=(Hashtable)malloc(sizeof(struct H_table));
    if(H==NULL)
    {
        printf("Out of space");
        return NULL;
    }
    H->table_size = next_prime(table_size);
    H->cell_array = (cell*) malloc(sizeof(cell) * H->table_size);    
    if(H->cell_array==NULL)
    {
        printf("Out of space");
        return NULL;
    }    
    for(int i=0;i< H->table_size;i++)
    {
        H->cell_array[i].info=Empty;
    }
    return H;
}
position find(int key,Hashtable H)
{
    position cur;
    int collision=0;
    cur=Hash(key,H->table_size);
    while(H->cell_array[cur].info!=Empty && H->cell_array[cur].data != key)
    {
        cur=(cur+1) % H->table_size;
    }
    return cur;
}
void insert(int key,Hashtable H)
{
    position pos=find(key,H);
    if(H->cell_array[pos].info!=Legitimate)
    {
        H->cell_array[pos].info=Legitimate;
        H->cell_array[pos].data=key;
    }
}
 
void display(Hashtable H)
{
    for(int i=0;i<H->table_size;i++)
    {
        printf("%d => %d\n",i,H->cell_array[i].data);
    }
}
int isFull(Hashtable H)
{
    int count=0;
    for(int i=0;i<H->table_size;i++)
    {
        if(H->cell_array[i].info==Legitimate)
        count++;
    }    
    if(count==H->table_size) return 1;
    else
        return 0;
}
void main()
{
    int size;
    printf("Enter size of the table: ");
    scanf("%d",&size);
    Hashtable H1=Create_table(size);
    printf("Hash table size: %d\n",H1->table_size);
    if(H1!=NULL)
    {
        int d,op;
        do
        {
            printf("\nChoose operation: 1) Insert 2) Display: ");
            scanf("%d",&op);
            
            switch(op)
            {
                case 1:
                if(isFull(H1))
                {
                    printf("Hash Table is full...\n");
                    break;
                }
                printf("Enter the data to be inserted: ");
                scanf("%d",&d);
                insert(d,H1);
                break;                
                case 2:
                printf("\nLinear probing hash table\n\n");
                display(H1);
                break;                
                case 0:
                printf("Operation terminated");
                break;                
                default:
                printf("Invalid operation...\n");
            } 
        }while(op);
    }
 }

Quadratic Probing:
#include <stdio.h>
#include<stdlib.h>
#define MINSIZE 7
typedef int index;
typedef index position;
typedef struct hash_entry cell;
typedef struct H_table* Hashtable;
enum entry { Legitimate, Empty, Deleted };

struct hash_entry
{
    int data;
    enum entry info;
};
struct H_table
{
    int table_size;
    cell* cell_array;
};
int next_prime(int table_size)
{
    int i=table_size,f;
    while(1)
    {
        f=1;
        for(int j=2;j<i;j++)
        {
            if(i%j==0)
            {
                f=0;
                break;
            }
        }
        if(f==1)
        return i;
        i++;
    }
}
 
index Hash(int key,int table_size)
{
    return key % table_size;
}
Hashtable Create_table(int table_size)
{
    Hashtable H;
    if(table_size < MINSIZE)
    {
        printf("Table size too small");
        return NULL;
    }
    H=(Hashtable)malloc(sizeof(struct H_table));
    if(H==NULL)
    {
        printf("Out of space");
        return NULL;
    }
    H->table_size = next_prime(table_size);
    H->cell_array = (cell*) malloc(sizeof(cell) * H->table_size);    
    if(H->cell_array==NULL)
    {
        printf("Out of space");
        return NULL;
    }    
    for(int i=0;i< H->table_size;i++)
    {
        H->cell_array[i].info=Empty;
    }
    return H;
}

position find(int key,Hashtable H)
{
    position cur;
    int collision=0;
    cur=Hash(key,H->table_size);
    while(H->cell_array[cur].info!=Empty && H->cell_array[cur].data != key)
    {
        cur=(cur+(2*(++collision)-1)) % H->table_size;
    }
    return cur;
}
void insert(int key,Hashtable H)
{
    position pos=find(key,H);
    if(H->cell_array[pos].info!=Legitimate)
    {
        H->cell_array[pos].info=Legitimate;
        H->cell_array[pos].data=key;
    }
}

void display(Hashtable H)
{
    for(int i=0;i<H->table_size;i++)
    {
        printf("%d => %d\n",i,H->cell_array[i].data);
    }
}
int isFull(Hashtable H)
{
    int count=0;
    for(int i=0;i<H->table_size;i++)
    {
        if(H->cell_array[i].info==Legitimate)
        count++;
    }    
    if(count==H->table_size) return 1;
    else
        return 0;
}
 
void main()
{
    int size;
    printf("Enter size of the table: ");
    scanf("%d",&size);
    Hashtable H1=Create_table(size);
    printf("Hash table size: %d\n",H1->table_size);
    if(H1!=NULL)
    {
        int d,op;
        do
        {
            printf("\nChoose operation: 1) Insert 2) Display: ");
            scanf("%d",&op);            
            switch(op)
            {
                case 1:
                if(isFull(H1))
                {
                    printf("Hash Table is full...\n");
                    break;
                }
                printf("Enter the data to be inserted: ");
                scanf("%d",&d);
                insert(d,H1);
                break;                
                case 2:
                printf("\nQuadratic probing hash table\n\n");
                display(H1);
                break;                
                case 0:
                printf("Operation terminated");
                break;                
                default:
                printf("Invalid operation...\n");
            } 
        }while(op);
    }
}

Rehashing:
#include <stdio.h>
#include<stdlib.h>
#define MINSIZE 7
typedef int index;
typedef index position;
typedef struct hash_entry cell;
typedef struct H_table* Hashtable;
enum entry { Legitimate, Empty, Deleted };
 
struct hash_entry
{
    int data;
    enum entry info;
};
struct H_table
{
    int table_size;
    cell* cell_array;
};
int next_prime(int table_size)
{
    int i=table_size,f;
    while(1)
    {
        f=1;
        for(int j=2;j<i;j++)
        {
            if(i%j==0)
            {
                f=0;
                break;
            }
        }
        if(f==1)
        return i;
        i++;
    }
}
int isFull(Hashtable H)
{
    int count=0;
    for(int i=0;i<H->table_size;i++)
    {
        if(H->cell_array[i].info==Legitimate)
        count++;
    }    
    if(count>H->table_size*0.75) return 1;
    else
        return 0;
}
index Hash(int key,int table_size)
{
    return key % table_size;
}
Hashtable Create_table(int table_size)
{
    Hashtable H;
    if(table_size < MINSIZE)
    {
        printf("Table size too small");
        return NULL;
    }
    H=(Hashtable)malloc(sizeof(struct H_table));
    if(H==NULL)
    {
        printf("Out of space");
        return NULL;
    }
    H->table_size = next_prime(table_size);
    H->cell_array = (cell*) malloc(sizeof(cell) * H->table_size);    
    if(H->cell_array==NULL)
    {
        printf("Out of space");
        return NULL;
    }    
    for(int i=0;i< H->table_size;i++)
    {
        H->cell_array[i].info=Empty;
    }
    return H; }

position find(int key,Hashtable H)
{
    position cur;
    int collision=0;
    cur=Hash(key,H->table_size);
    while(H->cell_array[cur].info!=Empty && H->cell_array[cur].data != key)
    {
        cur=(cur+1) % H->table_size;
    }
    return cur;
}
void insert(int key,Hashtable H)
{
    position pos=find(key,H);
    if(H->cell_array[pos].info!=Legitimate)
    {
        H->cell_array[pos].info=Legitimate;
        H->cell_array[pos].data=key;
    }
}
Hashtable Rehash(Hashtable H1)
{
    Hashtable H2=Create_table(H1->table_size*2);
    for(int i=0;i<H1->table_size;i++)
    {
        if(H1->cell_array[i].info==Legitimate)
        insert(H1->cell_array[i].data,H2);
    }
    return H2;
}
void display(Hashtable H)
{
    for(int i=0;i<H->table_size;i++)
    {
        printf("%d => %d\n",i,H->cell_array[i].data);
    }
}
void main()
{
    int size;
    printf("Enter size of the table: ");
    scanf("%d",&size);
    Hashtable H1=Create_table(size);
    printf("Hash table size: %d\n",H1->table_size);
    if(H1!=NULL)
    {
        int d,op;
        do
        {
            printf("\nChoose operation: 1) Insert 2) Display: ");
            scanf("%d",&op);
            switch(op)
            {
                case 1:
                if(isFull(H1))
                {
                    printf("\nRehashing the table from %d to",H1->table_size);
                    H1=Rehash(H1);
                    printf(" %d...\n\n",H1->table_size);
                }
                printf("Enter the data to be inserted: ");
                scanf("%d",&d);
                insert(d,H1);
                break;                
                case 2:
                printf("\nLinear probing hash table\n\n");
                display(H1);
                break;
                
                case 0:
                printf("Operation terminated");
                break;                
                default:
                printf("Invalid operation...\n");
            } 
        }while(op);
    }
}
 
Output:
Enter size of the table: 10
Hash table size: 11
Choose operation: 1) Insert 2) Display: 1
Enter the data to be inserted: 7
Choose operation: 1) Insert 2) Display: 1
Enter the data to be inserted: 18
Choose operation: 1) Insert 2) Display: 1
Enter the data to be inserted: 45
Choose operation: 1) Insert 2) Display: 1
Enter the data to be inserted: 93
Choose operation: 1) Insert 2) Display: 1
Enter the data to be inserted: 17

Choose operation: 1) Insert 2) Display: 1
Enter the data to be inserted: 69
Choose operation: 1) Insert 2) Display: 2

 
Linear probing hash table

0 => 0
1 => 45
2 => 0
3 => 69
4 => 0
5 => 93
6 => 17
7 => 7
8 => 18
9 => 0
10 => 0









Result:

Thus the program has been successfully executed.
 
SEPARATE CHAINING:

Program:
#include <stdio.h>
#include<stdlib.h>
#define MINSIZE 7

typedef int index;
typedef struct Node* position;
typedef struct Node*List;
typedef struct H_table* Hashtable;

struct Node
{
    int data;
    position next;
};

struct H_table
{
    int table_size;
    List* List_array;
};

 
int next_prime(int table_size)
{
    int i=table_size,f;
    while(1)
    {
        f=1;
        for(int j=2;j<i;j++)
        {
            if(i%j==0)
            {
                f=0;
                break;
            }
        }
        if(f==1)
        return i;
        i++;
    }
}

index Hash(int key,int table_size)
{
    return key % table_size;
}

Hashtable Create_table(int table_size)
{
    Hashtable H;
    if(table_size < MINSIZE)
    {
        printf("Table size too small");
        return NULL;
    }
    H=(Hashtable)malloc(sizeof(struct H_table));
    if(H==NULL)
    {
        printf("Out of space");
        return NULL;
    }
    H->table_size = next_prime(table_size);
    H->List_array = (List*) malloc(sizeof(List) * H->table_size);
    
    if(H->List_array==NULL)
    {
        printf("Out of space");
        return NULL;
    }
    for(int i=0;i< H->table_size;i++)
    {
        H->List_array[i]=(position)malloc(sizeof(struct Node));
        if(H->List_array[i]==NULL)
        {
            printf("Out of space");
            return NULL;
        }
        else
        {
            H->List_array[i]->next==NULL;
        }
    }
    return H;
}
position find(int key,Hashtable H)
{
    position p;
    List L;
    L=H->List_array[Hash(key,H->table_size)];
    p=L->next;
    while(p!=NULL && p->data!=key)
        p=p->next;
    return p;}

 
void insert(int key,Hashtable H)
{
    position p,new_cell;
    List L;
    p=find(key,H);
    if(p==NULL)
    {
        new_cell=(position)malloc(sizeof(struct Node));
        if(new_cell==NULL)
        printf("Out of space");
        else
        {
            new_cell->data=key;
            L=H->List_array[Hash(key,H->table_size)];
            new_cell->next=L->next;
            L->next=new_cell;
        }
    }
}

void display(Hashtable H){
 for(int i=0;i<H->table_size;i++){
        List L=H->List_array[i];
        printf("%d => ",i);
        position p=L->next;
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        printf("\n");
    }
}
int main()
{
    int size;
    printf("Enter size of the table: ");
    scanf("%d",&size);
    Hashtable H1=Create_table(size);
    printf("Hashtable Size: %d\n",H1->table_size);
    if(H1!=NULL)
    {
       int d,op;
        do
        {
            printf("\nChoose operation: 1) Insert 2) Display: ");
            scanf("%d",&op);
 
             switch(op)
            {
                case 1:
                printf("Enter the data to be inserted:");
                scanf("%d",&d);
                insert(d,H1);
                break;
                 case 2:
                printf("\nSeparate Chaining hash table\n\n");
                display(H1);
                break;
                
                case 0:
                printf("Operation terminated");
                break;
               default:
                printf("Invalid operation\n");
            } 
        } while(op);
    }
}


 
Output:
Enter size of the table: 10
Hashtable Size: 11

Choose operation: 1) Insert 2) Display: 1
Enter the data to be inserted: 15

Choose operation: 1) Insert 2) Display: 1
Enter the data to be inserted: 25

Choose operation: 1) Insert 2) Display: 1
Enter the data to be inserted: 35

Choose operation: 1) Insert 2) Display: 2

Separate Chaining hash table

0 => 
1 => 
2 => 
3 => 
4 => 
5 => 
6 => 
7 => 35 25 15 
8 => 
9 => 
10 => 

Choose operation: 1) Insert 2) Display: 1
Enter the data to be inserted: 45

Choose operation: 1) Insert 2) Display: 2

Separate Chaining hash table

0 => 
1 => 
2 => 
3 => 
4 => 
5 => 
6 => 
7 => 45 35 25 15 
8 => 
9 => 
10 => 

Choose operation: 1) Insert 2) Display: 0
Operation terminated
