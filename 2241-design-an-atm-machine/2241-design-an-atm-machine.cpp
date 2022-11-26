class ATM {
public:
    vector<long long> notes;
    vector<long long> den = {20,50,100,200, 500};
    ATM() {
        notes = vector<long long> (5);
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0 ; i < 5 ; ++i)
            notes[i] += banknotesCount[i];
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5);
        vector<long long> prev = notes;

        for(int i = 4 ; i>= 0 ; --i) {
            long long take=amount/den[i];
            take=min(take,notes[i]);
            amount -= take*den[i];
            ans[i]=take;
            notes[i]-=take;
        }
       
        if(amount) {
            notes = prev;
            return {-1};
            
        }
        else
            return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */