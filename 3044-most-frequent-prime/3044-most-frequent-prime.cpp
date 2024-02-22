class Solution {
public:
    bool isPrime(int n){
        for (int i=2; i<=sqrt(n); i++){
            if (n%i==0)return false;
        }
        return true;
    }
    int mostFrequentPrime(vector<vector<int>>& mat) {
        map<int,int> mp;
        int dx[8]= {1,1,1,-1,-1,-1,0,0};
        int dy[8]={1,0,-1,1,0,-1,1,-1};
        int n= mat.size(), m= mat[0].size();
        for (int sr=0; sr<n; sr++){
            for (int sc=0; sc<m; sc++){
                for (int it=0; it<8; it++){
                    int num=0;
                    int x= sr, y= sc;
                    while (x>=0 && x<n && y>=0 && y<m){
                        num= (num*10)+ mat[x][y];
                        x+= dx[it]; y+= dy[it];
                        mp[num]++;
                    }
                }
                
            }
        }
        int freq= -1, cnt=0;;
        for (auto &[val,fr]: mp){
            if (val>10 && isPrime(val)){
                if (fr>cnt){
                    freq= val;
                    cnt= fr;
                }else if (fr==cnt){
                    freq= max(val,freq);
                }    
            }
        }
        return freq;
    }
};
