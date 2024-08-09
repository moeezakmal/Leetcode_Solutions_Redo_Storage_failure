// Time: O(1)  -> because running till constant numbers given in problem description o.w. O(n)
// Space: O(1)


typedef struct {
    int n;
    int i;
    pthread_mutex_t lock;
    pthread_cond_t cond;
} FizzBuzz;

FizzBuzz* fizzBuzzCreate(int n) {
    FizzBuzz* obj = (FizzBuzz*) malloc(sizeof(FizzBuzz));
    obj->n = n;
    obj->i = 1;
    pthread_mutex_init(&obj->lock, NULL);
    pthread_cond_init(&obj->cond, NULL);
    return obj;
}

// printFizz() outputs "fizz".
void fizz(FizzBuzz* obj) {
    while(true){
        pthread_mutex_lock(&obj->lock); 
        while(obj->i <= obj->n && (obj->i % 3 != 0 || obj->i % 5 == 0))
            pthread_cond_wait(&obj->cond, &obj->lock);  
        if(obj->i > obj->n) {
            pthread_mutex_unlock(&obj->lock);
            pthread_exit(NULL);
        }
        printFizz();
        obj->i++;
        pthread_cond_broadcast(&obj->cond);
        pthread_mutex_unlock(&obj->lock);
    }
}

// printBuzz() outputs "buzz".
void buzz(FizzBuzz* obj) {
    while(true) {
        pthread_mutex_lock(&obj->lock); 
        while(obj->i <= obj->n && (obj->i % 3 == 0 || obj->i % 5 != 0))
            pthread_cond_wait(&obj->cond, &obj->lock);  
        if(obj->i > obj->n) {
            pthread_mutex_unlock(&obj->lock);
            pthread_exit(NULL);
        }
        printBuzz();
        obj->i++;
        pthread_cond_broadcast(&obj->cond);
        pthread_mutex_unlock(&obj->lock);
    }
}

// printFizzBuzz() outputs "fizzbuzz".
void fizzbuzz(FizzBuzz* obj) {
    while(true) {
        pthread_mutex_lock(&obj->lock); 
        while(obj->i <= obj->n && (obj->i % 3 != 0 || obj->i % 5 != 0))
            pthread_cond_wait(&obj->cond, &obj->lock);  
        if(obj->i > obj->n) {
            pthread_mutex_unlock(&obj->lock);
            pthread_exit(NULL);
        }
        printFizzBuzz();
        obj->i++;
        pthread_cond_broadcast(&obj->cond);
        pthread_mutex_unlock(&obj->lock);
    }
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.
void number(FizzBuzz* obj) {
    while(true) {
        pthread_mutex_lock(&obj->lock); 
        while(obj->i <= obj->n && (obj->i % 3 == 0 || obj->i % 5 == 0))
            pthread_cond_wait(&obj->cond, &obj->lock);  
        if(obj->i > obj->n) {
            pthread_mutex_unlock(&obj->lock);
            pthread_exit(NULL);
        }
        printNumber(obj->i);
        obj->i++;
        pthread_cond_broadcast(&obj->cond);
        pthread_mutex_unlock(&obj->lock);
    }   
}

void fizzBuzzFree(FizzBuzz* obj) {
    free(obj);
}