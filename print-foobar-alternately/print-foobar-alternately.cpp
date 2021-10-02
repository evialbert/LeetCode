class FooBar {
private:
    int n;
    bool is_foo =  true;
    std::mutex mtx;   
    std::condition_variable cv;
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (size_t i = 0; i < n; ++i) {
            std::unique_lock<std::mutex> lk(mtx);
            cv.wait(lk, [this]{return is_foo==true;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            is_foo=false;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (size_t i = 0; i < n; ++i) {
             std::unique_lock<std::mutex> lk(mtx);
             cv.wait(lk, [this]{return is_foo==false;});
        	 // printBar() outputs "bar". Do not change or remove this line.
        	 printBar();
             is_foo=true;
             cv.notify_one();
        }
    }
};