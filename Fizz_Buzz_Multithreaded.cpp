// Time: O(1)  -> because running till constant numbers given in problem description o.w. O(n)
// Space: O(1)

// Note: Remember to note the signature of functions passed as arguments/parameters

class FizzBuzz {
private:
    int n;
    int i;
    mutex mtx;
    condition_variable convar;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(true)
        {
            unique_lock<mutex> lock(mtx);
            convar.wait(lock, [&]{return (i%3==0 && i%5!=0) || i>n;});
            if (i>n) return;
            printFizz();
            ++i;
            convar.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(true)
        {
            unique_lock<mutex> lock(mtx);
            convar.wait(lock, [&]{return (i%3!=0 && i%5==0) || i>n;});
            if (i>n) return;
            printBuzz();
            ++i;
            convar.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(true)
        {
            unique_lock<mutex> lock(mtx);
            convar.wait(lock, [&]{return (i%3==0 && i%5==0) || i>n;});
            if (i>n) return;
            printFizzBuzz();
            ++i;
            convar.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {     //printNumber() requires argument
        while(true)
        {
            unique_lock<mutex> lock(mtx);
            convar.wait(lock, [&]{return (i%3!=0 && i%5!=0) || i>n;});
            if (i>n) return;
            printNumber(i);
            ++i;
            convar.notify_all();
        }
    }
};