// Time: O(n)
// Space: O(n)


#define MAX_Q_Size 1000

typedef struct {
    int val;
    int oper;
} node;

typedef struct {
    node* data;
    int front;
    int rear;
    int size;
} Queue;


Queue* createQueue() {
    Queue *obj = (Queue*)malloc(sizeof(Queue));
    obj->data = (node*)malloc(MAX_Q_Size*sizeof(node));
    obj->front = 0;
    obj->rear = 0;
    obj->size = 0;
    return obj;
}

void enqueue(Queue* obj, int x, int _oper) {
    obj->data[obj->rear].val = x;
    obj->data[obj->rear].oper = _oper;
    obj->rear = (obj->rear + 1) % MAX_Q_Size;
    obj->size++;
}

node dequeue(Queue* obj) {
    node newNode;
    newNode.val = obj->data[obj->front].val;
    newNode.oper = obj->data[obj->front].oper;
    obj->front = (obj->front + 1) % MAX_Q_Size;
    obj->size--;
    return newNode;
}

bool isQEmpty(Queue* obj) {
    return (obj->size == 0);
}

void freeQ(Queue* obj) {
    free(obj);
}

int minimumOperationsToMakeEqual(int x, int y) {
    
    if (y>=x)
        return y-x;
    
    Queue *q = createQueue();
    bool* visited = (bool*)calloc(x*2, sizeof(bool));
    enqueue(q, x, 0);
    visited[x] = true;

    while(!isQEmpty(q))
    {
        node temp = dequeue(q);

        if (temp.val == y)
            return temp.oper;


        if (temp.val % 11 == 0)
        {
            if(!visited[temp.val/11])
            {
                enqueue(q, temp.val/11, temp.oper+1);
                visited[temp.val/11] = true;
            }
        }

        if (temp.val % 5 == 0)
        {
            if(!visited[temp.val/5])
            {
                enqueue(q, temp.val/5, temp.oper+1);
                visited[temp.val/5] = true;
            }
        }

        if (temp.val > 0)
        {
            if(!visited[temp.val-1])
            {   
                enqueue(q, temp.val-1, temp.oper+1);
                visited[temp.val-1] = true;
            }
        }

        if(!visited[temp.val+1])
        {
            enqueue(q, temp.val+1, temp.oper+1);
            visited[temp.val+1] = true;
        }
    }

    return -1;

}