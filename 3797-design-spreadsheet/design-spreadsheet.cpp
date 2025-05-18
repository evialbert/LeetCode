class Spreadsheet {
public:
    vector<vector<int>>ss;
    Spreadsheet(int rows) {
        ss.resize(rows, vector<int>(26, 0));
    }

    pair<int, int> findcell(string c){
        int row, col=c[0]-'A';
        //cout<<c;
        row = stoi(c.substr(1, c.length()-1));
        return {row-1, col};
    }
    
    void setCell(string cell, int value) {
        auto loc = findcell(cell);
        ss[loc.first][loc.second]=value;
        return;
    }
    
    void resetCell(string cell) {
        setCell(cell, 0);
        return;
    }
    
    int getValue(string s) {
        int k, n=s.length(), v1, v2;
        for(int i=0;i<n;i++)if(s[i]=='+'){k=i;break;}
        string s1=s.substr(1, k-1), s2=s.substr(k+1);
        //cout<<s1<<' '<<s2;
        if((s1[0]>='A') && (s1[0]<='Z')){
            auto p = findcell(s1);
            v1=ss[p.first][p.second];
        }
        else v1 = stoi(s1);

        if((s2[0]>='A') && (s2[0]<='Z')){
            auto p = findcell(s2);
            v2=ss[p.first][p.second];
        }
        else v2 = stoi(s2);

        return (v1+v2);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */