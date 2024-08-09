// Time: O(1) -> for every operation
// Space: O(n) -> for every operation


class BoundedBlockingQueue {
public:
    queue<int> que;
    int capacity;
    pthread_cond_t cond;
    pthread_mutex_t mtx;

    BoundedBlockingQueue(int capacity) {
        pthread_mutex_init(&mtx, NULL);
        pthread_cond_init(&cond, NULL);
        this->capacity = capacity;
    }
    
    void enqueue(int element) {
        pthread_mutex_lock(&mtx);

        while(que.size() == capacity) {
            pthread_cond_wait(&cond, &mtx);
        }

        que.push(element);
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mtx);
    }
    
    int dequeue() {
        pthread_mutex_lock(&mtx);
        while(que.size() == 0) {
            pthread_cond_wait(&cond, &mtx);
        }
        int top = que.front(); que.pop();
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mtx);

        return top;
    }
    
    int size() {
        pthread_mutex_lock(&mtx);
        int ret = que.size();
        pthread_mutex_unlock(&mtx);
        return ret;
    }
};