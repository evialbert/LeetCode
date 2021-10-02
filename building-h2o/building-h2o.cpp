class H2O {
public:
    int hCount = 0, oCount = 0;
    mutex mtx;
    condition_variable cv;
    H2O() { }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lck(mtx);
        while(hCount - oCount * 2 >= 2)
        {
            cv.wait(lck);
        }
        
        cv.notify_all();
        ++hCount;
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lck(mtx);
        while(oCount * 2 - hCount > 0)
        {
            cv.wait(lck);
        }
        
        cv.notify_all();
        ++oCount;
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
    }
};