// Time: O(n)
// Space: O(1)

typedef struct 
{
    int         n;

    sem_t       foo_; 
    sem_t       bar_; 
    
} FooBar;

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;

    sem_init(& obj->foo_, 0, 0); 
    sem_init(& obj->bar_, 0, 1); 

    return obj;
}

void foo(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++)
    {
        sem_wait(& obj->bar_); 

        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();

        sem_post(& obj->foo_); 
    }
}

void bar(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++)
    {
        sem_wait(& obj->foo_); 

        // printBar() outputs "bar". Do not change or remove this line.
        printBar();

        sem_post(& obj->bar_); 
    }
}

void fooBarFree(FooBar* obj)
{
    sem_destroy(& obj->foo_); 
    sem_destroy(& obj->bar_); 
}