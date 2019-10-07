#include<stdio.h>
#include<malloc.h>
#define M 20
#define INF 1000

typedef struct NODE
{
	int v;
	int w;
	struct NODE* next;
}node;

typedef struct HeapNode
{
	int v;
	int dis;
}Hnode;

int minvert(int* dist,int* visit,int n)
{ 
	int i,min=INF,u;
	for(i=1;i<n;i++)
	{
		if(visit[i]==0&&dist[i]<min)
		{
			u=i;
			min=dist[i];
		}
			
	}
	return u;
}

void printpath(int *pred,int x)
{
	if(pred[x]==-1)
	{
		printf(" %d",x);
		return;
	}	
	printpath(pred,pred[x]);
	printf("-->%d",x);
}

void Dijkstra(node *L[], int n)
{
	int u,v,i;
	int *dis,*pre,*vis,pos[n+1];
	dis=(int *)malloc((n+1)*sizeof(int));
	pre=(int *)malloc((n+1)*sizeof(int));
	vis=(int *)malloc((n+1)*sizeof(int));
	
	int Hsize = n;
	Hnode *H = (Hnode *)malloc((Hsize+1)*sizeof(Hnode));
	
	for(i=1;i<n+1;i++)
	{
		dis[i]=H[i].dis=INF;
		pre[i]=-1;
		vis[i]=0;
	}
	
	dis[1]=H[1].dis=0; //assuming source vertex is 1
	
	for(i=1;i<=n;i++)
	{
		u=minvert(dis,vis,n+1);
		vis[u]=1;
		
		for(v=1;v<n+1;v++)
		{
			if(A[u][v]>-1&&vis[v]==0)
			{
				if(dis[v]>dis[u]+A[u][v])
				{
					dis[v]=dis[u]+A[u][v];
					pre[v]=u;
				}
			}
		}
		
	}
	
	printf("\nDistance");
	for(i=1;i<n+1;i++)
	{
		printf("\n%d %d",i,dis[i]);
		printpath(pre,i);
	}
	
}

int main()
{
	printf("\nNo. of vertices:");
	scanf("%d",&n);
	printf("\nNo. of edges:");
	scanf("%d",&e);
	node *List[N]={NULL};
	
	for(k=0;k<e;k++)
	{
		node *t = (node *)malloc(sizeof(node));
		printf("\nEnter an edge(i j w):");
		scanf("%d %d %d", &i, &j, &w);
		t->v=j;
		t->w=w;
		t->next = List[i];
		List[i] = t;
	}

	printf("\nInput Graph:\n");
	for(i=1;i<n+1;i++)
	{
		printf("\n\n%d",i);
		node *p=List[i];
		while(p!=NULL)
		{
			printf("->%d:%d",p->v,p->w);
			p=p->next;
		}
	}
	
	Dijkstra(List, n);
	
	return 0;
}
