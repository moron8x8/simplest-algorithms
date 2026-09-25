#include <stdio.h>

#define MAX_V 100

typedef struct {
  int to;
}edge;

typedef struct{
  edge edges[MAX_V];
  int degree;
}vertex;

typedef struct{
  vertex vertices[MAX_V];
  int vert;
}graph;


void addedges(graph *g, int u, int v)
{
  int degree = g->vertices[u].degree;
  if (degree >= MAX_V) return;
  
  g->vertices[u].edges[degree].to = v;
  g->vertices[u].degree = ++degree;
}

void BFS(graph *g, int start)
{
  int queue[g->vert + 1];
  int visited[g->vert];
  int first, last;

  for (int i = 0; i < g->vert; i++) visited[i] = 0;

  first = 0;
  last = 0;
  
  queue[last++] = start; 
  visited[start] = 1;

  while (last != first){
    int u = queue[first++];
    printf("%d ", u);

    for(int k = 0; k < g->vertices[u].degree; k++){
      
      int v = g->vertices[u].edges[k].to;

      if (!visited[v]){
        queue[last++] = v;
        visited[v] = 1;
      }
    }
  }
}

    
int main(void)
{
  int v, edges, start, u, t;
  graph g = {0};

  if (scanf("%d%d", &v, &edges) != 2 || v <= 0 || v > MAX_V || edges < 0) return 0;

  g.vert = v;

  for (int i = 0; i < edges; i++) {
    if (scanf("%d%d", &u, &t) != 2 || u < 0 || u >= v || t < 0 || t >= v) return 0;
    addedges(&g, u, t);
  }
  if(scanf("%d", &start) != 1 || start < 0 || start >= v) return 0;

  BFS(&g, start);

  putchar('\n');
  
  return 0;
}
