class FizzBuzz {
    private int n;
    Semaphore f = new Semaphore(0);
    Semaphore b = new Semaphore(0);
    Semaphore fb = new Semaphore(0);
    Semaphore num = new Semaphore(1);

    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        for(int i=1;i<=n;i++) {
            if(i%3==0 && i%5!=0)
            {
                f.acquire();
                  printFizz.run();
                if((i+1)%5==0 &&(i+1)%3==0)
                    fb.release();
                else if((i+1)%5==0)
                    b.release();
                else if((i+1)%3==0)
                    f.release();
                else
                    num.release();
            }
        }
        
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        
        for(int i=1;i<=n;i++) {
            if(i%5==0 && i%3!=0)
            {
                b.acquire();
                  printBuzz.run();
                if((i+1)%5==0 &&(i+1)%3==0)
                    fb.release();
                else if((i+1)%5==0)
                    b.release();
                else if((i+1)%3==0)
                    f.release();
                else
                    num.release();
            }
        }
        
        
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for(int i=1;i<=n;i++) {
            if(i%3==0 && i%5==0)
            {
                fb.acquire();
                  printFizzBuzz.run();
                if((i+1)%5==0 &&(i+1)%3==0)
                    fb.release();
                else if((i+1)%5==0)
                    b.release();
                else if((i+1)%3==0)
                    f.release();
                else
                    num.release();
            }
        }
        
        
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        for(int i=1;i<=n;i++) {
            if(i%3!=0 && i%5!=0)
            {
                num.acquire();
                  printNumber.accept(i);
                if((i+1)%5==0 &&(i+1)%3==0)
                    fb.release();
                else if((i+1)%5==0)
                    b.release();
                else if((i+1)%3==0)
                    f.release();
                else
                    num.release();
            }
        }
        
        
    }
}