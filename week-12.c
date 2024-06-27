Write a C program to create a graph and display the ordering of vertices.  




Aim:
Write a C program to create a graph and display the ordering of vertices (TOPOLOGICAL SORT)


Algorithm:

Step 1: Find the indegree for every vertex.
Step 2: Place the vertices whose indegree is 0 on the empty queue.
Step 3: Dequeue the vertex v and decrement the indegree of all its adjacent vertices.
Step 4: Enqueue the vertex on the queue if its indegree falls to zero.
Step 5: Repeat from step 3 until the queue becomes empty.
Step 6: The topological ordering is the order in which the vertices dequeue.  



















 
Program:

#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
typedef struct Node* pos;
typedef struct Node* Vert;
typedef struct Graph_parts* Graph;
typedef int Queue;

int front=-1,rear=-1;
Queue Q[50];

void enqueue(int n)
{
    if(front==-1)
        front++;
    rear++;
    Q[rear]=n;
}

int dequeue()
{
    int p=Q[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
        front++;
    return p;
}
 
struct Node
{
    int data;
    pos next;
};

struct Graph_parts
{
    int vertices;
    int edges;
    Vert* List;
};

void Link(Graph G, int v1, int v2)
{
    Vert n = (Vert)malloc(sizeof(Node));
    if(n!=NULL)
    {
         n->data = v2;
         pos p=G->List[v1];
         n->next=p->next;
         p->next=n;
    }
}

void Get_edges(Graph G)
{
    int v1,v2,cost;
    printf("Enter the edges:\n");
    for(int i=0;i<G->edges;i++)
    {
        printf("=> ");
        scanf("%d %d", &v1, &v2);
        Link(G,v1,v2);
    }
}
 
Graph Create_graph()
{
    Graph G = (Graph)malloc(sizeof(struct Graph_parts));
    if(G!=NULL)
    {  
        printf("Enter the number of vertices in graph: ");
        scanf("%d", &G->vertices);
        printf("Vertices are from 0 to %d\n",G->vertices-1);
       
        printf("\nEnter the number of edges: ");
        scanf("%d",&G->edges);
       
        G->List = (Vert*)malloc(sizeof(Node) * G->vertices);
        if(G->List!=NULL)
        {
            for (int i = 0; i < G->vertices; i++)
            {
                G->List[i] = (Vert)malloc(sizeof(struct Node));
            }
        }
        Get_edges(G);
        return G;
    }
}

void Display(Graph G)
{
    printf("\nDisplaying the Graph using List\n\n");
    for (int i = 0; i < G->vertices; i++)
    {
        struct Node* p = G->List[i];
        printf("%d => ", i);
        p=p->next;
 
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

void mark_all_zeros(int v[],int in[],int size)
{
    for(int i=0;i<size;i++)
    {
        in[i]=0;
        v[i]=0;
    }
}

void find_indegree(Graph G,int in_deg[])
{
    pos p;
    for(int i=0;i<G->vertices;i++)
    {
        p=G->List[i]->next;
        while(p!=NULL)
        {
            in_deg[p->data]++;
            p=p->next;
        }
    }
}

 
void Topo_sort(Graph G,int vis[],int in_deg[])
{
    int arr[G->vertices];
    int s=0;
    int i,j=0;
    while(j<G->vertices)
    {
        for(i=0;i<G->vertices;i++)
        {
            if(in_deg[i]==0 && vis[i]==0)
            {
                enqueue(i);
                vis[i]=1;
            }
        }
        if(front!=-1)
        {
            int n=dequeue();
            arr[s]=n;
            s++;
            pos p=G->List[n]->next;
            while(p!=NULL)
            {
                in_deg[p->data]--;
                p=p->next;
            }
        }
        else
            break;
        j++;
    }
    if(j==G->vertices)
    {
        printf("\nTopological sort for the given graph is:\n");
 
        for(int k=0;k<G->vertices;k++)
        {
            printf("%d ",arr[k]);
        }
    }
    else
    {
        printf("Graph has a cycle");
    }
}

void main()
{
    Graph G=Create_graph();
    Display(G);
    int visited[G->vertices];
    int indegree[G->vertices];
    mark_all_zeros(visited,indegree,G->vertices);
    find_indegree(G,indegree);
    Topo_sort(G,visited,indegree);
}
 
Output:

Enter the number of vertices in graph: 3
Vertices are from 0 to 2
Enter the number of edges: 3
Enter the edges:
=> 0 1
=> 0 2
=> 1 2
Displaying the Graph using List
0 => 2 1 
1 => 2 
2 => 
Topological sort for the given graph is:
0 1 2
