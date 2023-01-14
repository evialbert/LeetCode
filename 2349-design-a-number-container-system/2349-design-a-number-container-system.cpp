class NumberContainers {
public:
    NumberContainers() {
        
    }
    map<int, int> m1;
    map<int, set<int>> m2;

    void change(int index, int number) {
        m2[number].insert(index);
        if(m1.find(index)!=m1.end() and m1[index]!=number)
        {
            int x=m1[index];
            m2[x].erase(m2[x].find(index));
            m1[index]=number;
        }
        else
            m1[index]=number;
        
    }
    
    int find(int number) {
        
        int ans =-1;
        if(m2[number].size()==0) return ans;
        else
            ans= *m2[number].begin();
        return ans;
        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */