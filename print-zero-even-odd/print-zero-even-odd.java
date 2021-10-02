class ZeroEvenOdd {
    private int n;
    private boolean flag = true;
    private int count=1;
    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        while(count<=n)
        { 
        synchronized(this)
        {    
            while(!flag)
                wait();
            if(count<=n)
                printNumber.accept(0);
           flag=false;
            notifyAll();
        }
        }    
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        while(count<=n)
        {    
        synchronized(this)
        {    
            while(flag || count%2!=0)
                wait();
            
           if(count<=n)
               printNumber.accept(count);
           
            flag=true;
            count++;
            notifyAll();
        }
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        while(count<=n)
        {
        synchronized(this)
        {    
            while(flag || count%2==0)
                wait();
           if(count<=n)
               printNumber.accept(count);
           flag=true;
            count++;
            notifyAll();
        }
        }    
    }
}