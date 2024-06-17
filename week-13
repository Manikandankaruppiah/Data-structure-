Write a C program to create a graph and find a minimum spanning tree using prims algorithm. 

Aim:
To write a c program to create a graph and find a minimum spanning tree using prim’s algorithm.

Algorithm:
	
1. Initialize `key[]` to `INT_MAX`, `key[0]` to 0, `mstSet[]` to `false`, and `parent[]` to `-1`.
2. For count` from 0 to `numvertex 1:
•	Select vertex `u` with minimum `key[u]` that is not `mstSet`.
•	Set `mstSet[u]` to `true`.
•	For each adjacent vertex `v` of `u`:
If `weight(u, v) < key [v]` and `v` is not in `mstset`, update `key[v]` and set `parent[v]` to `u`.
3. Repeat until all vertices are processed.

 
Program:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define infinity 10000;

struct node {
    int vertex;
    int w;
    struct node *next;
};

struct graph {
    int numvertex;
    struct node **adjlist;
};

struct node* create_node(int vertex, int w) {
    struct node *new = (struct node*)malloc(sizeof(struct node));
    if (!new) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    new->vertex = vertex;
    new->w = w;
    new->next = NULL;
    return new;
}

struct graph* create_graph(int no) {
    struct graph *new = (struct graph*)malloc(sizeof(struct graph));
    if (!new) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    new->numvertex = no;
    new->adjlist = (struct node**)malloc(no * sizeof(struct node*));
    if (!new->adjlist) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < no; i++) {
        new->adjlist[i] = NULL;
    }
    return new;
}

void add_edge(struct graph *g, int s, int d, int w) {
    struct node *new = create_node(d, w);
    new->next = g->adjlist[s];
    g->adjlist[s] = new;
    new = create_node(s, w);
    new->next = g->adjlist[d];
    g->adjlist[d] = new;
}

struct graph* input(struct graph *g) {
    int no, d, s, w;
    printf("ENTER THE NO. OF EDGES: ");
    scanf("%d", &no);
    for (int i = 0; i < no; i++) {
        printf("Enter edge (source destination weight): ");
        scanf("%d %d %d", &s, &d, &w);
        add_edge(g, s, d, w);
    }
    return g;
}

void print_graph(struct graph *g) {
    for (int i = 0; i < g->numvertex; i++) {
        struct node *temp = g->adjlist[i];
  
       printf("VERTEX %d\n", i);
        while (temp != NULL) {
            printf("%d(%d) --> ", temp->vertex, temp->w);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void free_graph(struct graph *g) {
    for (int i = 0; i < g->numvertex; i++) {
        struct node *temp = g->adjlist[i];
        while (temp != NULL) {
            struct node *to_free = temp;
            temp = temp->next;
            free(to_free);
        }
    }
    free(g->adjlist);
    free(g);
}

void prim_mst(struct graph *g) {
    int numvertex = g->numvertex;
    int path[numvertex];
    int dist[numvertex];
    bool known[numvertex];
    for (int i = 0; i < numvertex; i++) {
        dist[i] = infinity;
        known[i] = false;
    }
    dist[0] = 0;
    path[0] = -1;
 
 
   for (int count = 0; count < numvertex - 1; count++) {
        int u = -1;
        int min = infinity;
        for (int v = 0; v < numvertex; v++) {
            if (!known[v] && dist[v] < min) {
                min = dist[v];
                u = v;
            }
        }
        if (u == -1) {
            printf("Graph is disconnected\n");
            return;
        }
        known[u] = true;
        struct node *temp = g->adjlist[u];
        while (temp != NULL) {
            int v = temp->vertex;
            if (!known[v] && temp->w < dist[v]) {
                path[v] = u;
                dist[v] = temp->w;
            }
            temp = temp->next;
        }
    }
    printf("Path \tDistance\n");
    for (int i = 1; i < numvertex; i++) {
        if (path[i] != -1) {
            printf("%d - %d \t%d \n", path[i], i, dist[i]);
        }
    }
}
 
int main() {
    int n;
    printf("ENTER THE NO. OF NODES: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Number of nodes must be greater than 0\n");
        return -1;
    }
    struct graph *g = create_graph(n);
    input(g);
    print_graph(g);
    printf("\n\nMinimum Spanning Tree (MST) using Prim's Algorithm:\n\n");
    prim_mst(g);
    free_graph(g);
    return 0;
}

 
Output:

ENTER THE NO. OF NODES: 7
ENTER THE NO. OF EDGES: 9

Enter edge (source destination weight): 0 1 28
Enter edge (source destination weight): 1 2 16
Enter edge (source destination weight): 2 3 12
Enter edge (source destination weight): 3 4 22
Enter edge (source destination weight): 4 5 25
Enter edge (source destination weight): 5 0 10
Enter edge (source destination weight): 4 6 24
Enter edge (source destination weight): 2 6 18
Enter edge (source destination weight): 6 1 14

VERTEX 0
5(10) --> 1(28) --> NULL
VERTEX 1
6(14) --> 2(16) --> 0(28) --> NULL
VERTEX 2
6(18) --> 3(12) --> 1(16) --> NULL
VERTEX 3
4(22) --> 2(12) --> NULL
VERTEX 4
6(24) --> 5(25) --> 3(22) --> NULL
VERTEX 5
0(10) --> 4(25) --> NULL
VERTEX 6
1(14) --> 2(18) --> 4(24) --> NULL


Minimum Spanning Tree (MST) using Prim's Algorithm:

Path 	Distance
2 - 1 	16 
3 - 2 	12 
4 - 3 	22 
5 - 4 	25 
0 - 5 	10 
1 - 6 	14 

