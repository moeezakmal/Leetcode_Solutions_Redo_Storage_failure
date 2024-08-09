// Time: O(1)
// Space: O(1)

typedef struct {
    // User defined data may be declared here.
    int o;
    int h;
    pthread_mutex_t m;
    pthread_condattr_t ao;
    pthread_condattr_t ah;
    pthread_cond_t co;
    pthread_cond_t ch;
} H2O;

H2O* h2oCreate() {
    H2O* obj = (H2O*) malloc(sizeof(H2O));
    
    // Initialize user defined data here.
    obj->o=1;
    obj->h=2;
    pthread_mutex_init(&obj->m, NULL);
    pthread_cond_init(&obj->co, &obj->ao);
    pthread_cond_init(&obj->ch, &obj->ah);

    return obj;
}

void next(H2O* obj) {
    obj->h=2; obj->o=1;
    pthread_cond_signal(&obj->co);
    pthread_cond_signal(&obj->ch);
    pthread_cond_signal(&obj->ch);
}

void hydrogen(H2O* obj) {
    pthread_mutex_lock(&obj->m);
    while(obj->h == 0) pthread_cond_wait(&obj->ch, &obj->m);
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    releaseHydrogen();
    obj->h--;
    if(obj->h==0 && obj->o==0) next(obj);
    pthread_mutex_unlock(&obj->m);
}

void oxygen(H2O* obj) {
    pthread_mutex_lock(&obj->m);
    while(obj->o == 0) pthread_cond_wait(&obj->co, &obj->m);
    // releaseOxygen() outputs "O". Do not change or remove this line.
    releaseOxygen();
    obj->o--;
    if(obj->h==0 && obj->o==0) next(obj);
    pthread_mutex_unlock(&obj->m);
}

void h2oFree(H2O* obj) {
    // User defined data may be cleaned up here.
    pthread_mutex_destroy(&obj->m);
    pthread_cond_destroy(&obj->co);
    pthread_cond_destroy(&obj->ch);
}