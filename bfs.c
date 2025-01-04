#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
typedef struct node { // to represent vertex and edges
int data;
int status;
struct node *next,*point;
} node;

int d[SIZE],f[SIZE],time;
node *q[SIZE]; //to maintain queue
int front=0,rear=0; //to store queue
node*g=0;

//function to add vertices
void addvertices(int n)
{
node *t=(node*)malloc(sizeof(node));
t->data=n;
t->point=0;
t->next=g;
g=t;
}
//function to find vertex node address of a vertex
node *find(int n)
{
node*t=g;
while(t!=0&&t->data!=n)
t=t->next;
return t;
}
//function to add an edge
void addedge(int u,int v)
{
node *v1,*v2,*t;
v1=find(u);
v2=find(v);
t=(node*)malloc(sizeof(node));
t->next=v1->point;
v1->point=t;
t->point=v2;
return;
}
//function to print a graph
void printgraph(node*g)
{
node *t1,*t2,*t3;
printf("\n vertex\t Edgelist\n");
t1=g;
while(t1!=0)
{
printf("\n%d\t",t1->data);
t2=t1->point;
while(t2!=0)
{
t3=t2->point;
printf("%d ",t3->data);
t2=t2->next;
}
t1=t1->next;
}
}

void enque(node *s)
{
int r1=rear;
r1=(r1+1)%SIZE;
if(front==r1)
{
printf("queue full");
exit(1);
}
rear=r1;
q[rear]=s;
}
//empty queue to test queue empty or note
int empty()
{
if(front==rear)
return 1;
else
return 0;
}
//deque operation
node* deque()
{
if(empty())
{
printf("empty queue");
exit(2);
}
front=(front+1)%SIZE;
return q[front];
}
//bfs visit
void bfs(node *s)
{
node *t=g,*t1,*u;
while(t!=0)
{
t->status=0;//set all vertes as not visited
t=t->next;
}
s->status=1;//visit stat vertex
printf("%d ",s->data);
enque(s);
while(!empty())
{
u=deque();
t=u->point;
while(t!=0)
{
t1=t->point;
if(t1->status==0)
{
printf("%d ",t1->data);
t1->status=1;
enque(t1);
}
t=t->next;
}
}
}
//main function
int main()
{
addvertices(1);
addvertices(2);
addvertices(3);
addvertices(4);
addvertices(5);
addedge(1,2);
addedge(1,4);
addedge(2,3);
addedge(2,4);
addedge(4,3);
addedge(4,5);
printf("The graph is:\n");
printgraph(g);
printf("\n BFS traverse:");
bfs(find(1));
}

