// Time: O(n)
// Space: O(n)

int count;

typedef struct {
    int neighbor;
    int sign;
} Edge;

void dfs(int node, int parent, Edge** adj, int* adjSize);


int minReorder(int n, int** connections, int connectionsSize, int* connectionsColSize) {
    
    count = 0;
    
    Edge** adj = (Edge**)malloc(n*sizeof(Edge*));
    int* adjSize = (int*)calloc(n,sizeof(int));
    for (int i=0; i<n; i++)
        adj[i] = NULL;
    
    for (int i=0; i<connectionsSize; i++)
    {
        int u = connections[i][0];
        int v = connections[i][1];

        adj[u] = (Edge*)realloc(adj[u], (adjSize[u] + 1) * sizeof(Edge));
        adj[v] = (Edge*)realloc(adj[v], (adjSize[v] + 1) * sizeof(Edge));

        adj[u][adjSize[u]].neighbor = v;
        adj[u][adjSize[u]++].sign = 1;

        adj[v][adjSize[v]].neighbor = u;
        adj[v][adjSize[v]++].sign = 0;
    }
    dfs(0, -1, adj, adjSize);

    for (int i=0; i<n; i++)
        free(adj[i]);
    
    free(adj);
    free(adjSize);
    
    return count;
}


void dfs(int node, int parent, Edge** adj, int* adjSize) {
    for (int i=0; i< adjSize[node]; i++) 
    {
        int neighbor = adj[node][i].neighbor;
        int sign = adj[node][i].sign;
        if (neighbor != parent)
        {
            count += sign;
            dfs(neighbor, node, adj, adjSize);
        }
    }
}