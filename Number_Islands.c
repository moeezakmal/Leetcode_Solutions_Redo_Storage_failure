// Time: O(nm)
// Space: O(nm)



/*----------------BFS------------------*/

#define MAX_Q_Size 1000

typedef struct {
    int row;
    int col;
} QElement;

typedef struct {
    QElement *data;
    int front;
    int rear;
    int size;
} Queue;


Queue* createQueue() {
    Queue *obj = (Queue*)malloc(sizeof(Queue));
    obj->data = (QElement*)malloc(MAX_Q_Size*sizeof(QElement));
    obj->front = 0;
    obj->rear = 0;
    obj->size = 0;
    return obj;
}

void enqueue(Queue* obj, int i, int j) {
    obj->data[obj->rear].row = i;
    obj->data[obj->rear].col = j;
    obj->rear = (obj->rear + 1) % MAX_Q_Size;
    obj->size++;
}

void dequeue(Queue* obj, int* i, int* j) {
    *i = obj->data[obj->front].row;
    *j = obj->data[obj->front].col;
    obj->front = (obj->front + 1) % MAX_Q_Size;
    obj->size--;
}

bool isQEmpty(Queue* obj) {
    return (obj->size == 0);
}

void freeQ(Queue* obj) {
    free(obj->data);
    free(obj);
}


bool boundary(int i, int j, int n, int m) {
    return (0<=i) && (i<n) && (0<=j) && (j<m);
}


void bfs(char** grid, int i, int j, int n, int m) {
    Queue *q = createQueue();
    enqueue(q, i, j);
    grid[i][j]++;

    while (!isQEmpty(q))
    {
        int row, col;
        dequeue(q, &row, &col);
        QElement adj[4]={{row-1, col}, {row+1, col},{row, col-1},{row, col+1}};
        for(int k=0; k<4; k++) { 
            if (!boundary(adj[k].row, adj[k].col, n, m) || grid[adj[k].row][adj[k].col]!='1') 
                continue;
            enqueue(q, adj[k].row, adj[k].col);
            grid[adj[k].row][adj[k].col]++;
        }
    }
    freeQ(q);
}


/*----------------DFS------------------*/

void dfs(char** grid, int i, int j, int rows, int cols) {
    if (!boundary(i, j, rows, cols))
        return;
    if (grid[i][j] == '1') {
        grid[i][j]++;
        dfs(grid, i+1, j, rows, cols);
        dfs(grid, i, j+1, rows, cols);
        dfs(grid, i-1, j, rows, cols);
        dfs(grid, i, j-1, rows, cols);
    }
}


int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (grid == NULL)
        return 0;

    int rows = gridSize;
    int cols = *gridColSize;

    int islands = 0;

    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            if (grid[i][j] == '1') {
                bfs(grid, i, j, rows, cols);
                // dfs(grid, i, j, rows, cols);
                islands++;
            }
        }
    }
    return islands;
}