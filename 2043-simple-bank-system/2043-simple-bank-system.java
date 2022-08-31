class Bank {
    long a[];
    public Bank(long[] balance) {
        a=balance;
        
    }
    
    public boolean transfer(int account1, int account2, long money) {
        if(account1-1>=a.length||account2-1>=a.length)
            return false;
       
        if(a[account1-1]<money)
        {
            return false;
        }
        a[account1-1]-=money;
        a[account2-1]+=money;
        return true;
    }
    
    public boolean deposit(int account, long money) {
        if(account-1>=a.length)
            return false;
        a[account-1]+=money;
        return true;
    }
    
    public boolean withdraw(int account, long money) {
        if(account-1>=a.length)
            return false;
        if(a[account-1]<money)
            return false;
        a[account-1]-=money;
        return true;
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * Bank obj = new Bank(balance);
 * boolean param_1 = obj.transfer(account1,account2,money);
 * boolean param_2 = obj.deposit(account,money);
 * boolean param_3 = obj.withdraw(account,money);
 */