Write a C program to implement a Queue using Array and linked List implementation and execute the following operation on stack.
(i)	Enqueue 
(ii)	Dequeue
(iii)	Display the elements in a Queue

Aim:
	To implement queue using array and linked list and perform basic operations of queue.

Algorithm:

1.	Linked List implementation

* Define a structure for node which contains two parts: data and a pointer to the next node.

* Create a new node and put the data in the data part of new node. New node should be added to the end of previous node.

* To remove an element, first check if the queue is empty or not, if it is not empty, remove the first element and move the pointer pointing to the first node to the next node.

2.	Array Implementation

 *Create an array of any size and new variables: front and rear with initial value -1.

* To insert the data, first check if rear is equal to max size of array or not. If not equal, increment rear and add the new value to array.

* To delete the data, first check if queue is empty or not. If it is not empty, print the value and increment the value of front.
 
 Linked List implementation:

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}Node;

void enqueue(Node** queue,int val){
	Node* newnode=malloc(sizeof(Node));
	Node* cur;
	if(newnode){

		newnode->data =val;
		newnode->next = NULL;
		if(*queue==NULL){
			*queue = newnode;
			cur =*queue;
		}
		else{
			cur->next= newnode;
			cur = newnode;
		}
	}
	else{
		printf("\nMemory allocation failed\n");
		exit(1);
	}
}

void peek(Node* queue){
	if(queue){
		printf("\nThe first element in the queue is %d",queue->data);
	}
	else{
		printf("\nThe queue is empty");
		return;
	}
}

int dequeue(Node** queue){
	if(*queue){
		Node* temp = *queue;
		(*queue) = (*queue)->next;
		int x = temp->data;
		free(temp);
		return x;
	}
 
	else{
		printf("\nQueue is empty");
		return -1;
	}
}


void display(Node* queue){
	if(queue){
		while(queue){
			printf("%d\t",queue->data);
			queue = queue->next;
		}
	}
	else{
		printf("\nThe queue is empty");
		return;
	}
}

int main(){
	Node* queue= NULL;
	int n,choice;
	do{
		printf("\n1. ENQUEUE\n2. DEQUEUE \n3. PEEK \n4. DISPLAY \n5.EXIT");
		printf("\nENTER YOUR CHOICE: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				printf("\nEnter the element to enqueue: ");
				scanf("%d",&n);
				enqueue(&queue,n);
				break;
			}
			case 2:{
				n = dequeue(&queue);
				if(n!=-1){
					printf("\nThe dequeued element is %d",n);
					break;
				}
				}
			case 3: peek(queue); break;
			case 4: display(queue); break;
		}

	}while(choice<=4);
	
	return 0;
}

 
Output:

1. ENQUEUE
2. DEQUEUE 
3. PEEK 
4. DISPLAY 
5.EXIT
ENTER YOUR CHOICE: 1

Enter the element to enqueue: 2

1. ENQUEUE
2. DEQUEUE 
3. PEEK 
4. DISPLAY 
5.EXIT
ENTER YOUR CHOICE: 1

Enter the element to enqueue: 4

1. ENQUEUE
2. DEQUEUE 
3. PEEK 
4. DISPLAY 
5.EXIT
ENTER YOUR CHOICE: 1

Enter the element to enqueue: 5

1. ENQUEUE
2. DEQUEUE 
3. PEEK 
4. DISPLAY 
5.EXIT
ENTER YOUR CHOICE: 1

Enter the element to enqueue: 6

1. ENQUEUE
2. DEQUEUE 
3. PEEK 
4. DISPLAY 
5.EXIT
ENTER YOUR CHOICE: 2

The dequeued element is 2
1. ENQUEUE
2. DEQUEUE 
3. PEEK 
4. DISPLAY 
5.EXIT
ENTER YOUR CHOICE: 3

The first element in the queue is 4
1. ENQUEUE
2. DEQUEUE 
3. PEEK 
4. DISPLAY 
5.EXIT
ENTER YOUR CHOICE: 4
4	5	6	

1. ENQUEUE
2. DEQUEUE 
3. PEEK 
4. DISPLAY 
5.EXIT
ENTER YOUR CHOICE: 5
 
Array Implementation:

#include<stdio.h>
#define MAX 10
int queue[MAX],front=-1,rear = -1;

void enqueue(int v){
	if(front == MAX-1){
		printf("\nQueue is full");
		return;
	}
	queue[++rear] = v;
	if(front == -1){
		front++;
	}
}

int dequeue(){
	if(front ==-1){
		printf("\nQueue is empty");
		return -1;
	}
	int temp = queue[front];
	if(front == rear){
		front = -1;
		rear = -1;
	}
	front++;
	return temp;
}

void peek(){
	if(front ==-1){
		printf("\nQueue is empty");
		return;
	}
	printf("\nThe first element in the queue is %d",queue[front]);

}

void display(){
	if(front ==-1){
		printf("\nQueue is empty");
		return;
	}
	printf("\nGiven queue is ");
	for (int i =front;i<=rear;i++)
		printf("%d\t",queue[i]);
	printf("\n");
	
}
 

int main(){
	int n,choice;
	do{
		printf("\n1. ENQUEUE\n2. DEQUEUE \n3. PEEK \n4. DISPLAY \n5.EXIT");
		printf("\nENTER YOUR CHOICE: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				printf("\nEnter the element to enqueue: ");
				scanf("%d",&n);
				enqueue(n);
				break;
			}
			case 2:{
				n = dequeue();
				if(n!=-1){
					printf("\nThe dequeued element is %d",n);
					break;
				}
				}
			case 3: peek(); break;
			case 4: display(); break;
		}

	}while(choice<=4);
}

 
OUTPUT:
1. ENQUEUE
2. DEQUEUE 
3. PEEK 
4. DISPLAY 
5.EXIT
ENTER YOUR CHOICE: 1

Enter the element to enqueue: 2

1. ENQUEUE
2. DEQUEUE 
3. PEEK 
4. DISPLAY 
5.EXIT
ENTER YOUR CHOICE: 1

Enter the element to enqueue: 4

1. ENQUEUE
2. DEQUEUE 
3. PEEK 
4. DISPLAY 
5.EXIT
ENTER YOUR CHOICE: 1

Enter the element to enqueue: 6

1. ENQUEUE
2. DEQUEUE 
3. PEEK 
4. DISPLAY 
5.EXIT
ENTER YOUR CHOICE: 4

Given queue is 2	4	6	

1. ENQUEUE
2. DEQUEUE 
3. PEEK 
4. DISPLAY 
5.EXIT
ENTER YOUR CHOICE: 2
The dequeued element is 2

1. ENQUEUE
2. DEQUEUE 
3. PEEK 
4. DISPLAY 
5.EXIT
ENTER YOUR CHOICE: 3
The first element in the queue is 4
 
1. ENQUEUE
2. DEQUEUE 
3. PEEK 
4. DISPLAY 
5.EXIT
ENTER YOUR CHOICE: 4

Given queue is   4	6	

1. ENQUEUE
2. DEQUEUE 
3. PEEK 
4. DISPLAY 
5.EXIT
ENTER YOUR CHOICE: 5

