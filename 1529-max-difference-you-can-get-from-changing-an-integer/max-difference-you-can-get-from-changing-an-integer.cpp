class Solution {
public:
    int findMax(int num){
        string snum = to_string(num);
        int res = 0, i = 0, n = snum.size();
        while(i < n){
            if(snum[i] == '9'){
                res = res*10 + 9;
                i++;
            }
            else{
                break;
            }
        }
        if(i == n)
            return res;
        int x = snum[i] - '0';
        while(i < n){
            int d = snum[i] - '0';
            if(d == x){
                res = res*10 + 9;
            }
            else{
                res = res*10 + d;
            }
            i++;
        }
        return res;
    }

    int findMin(int num){
        string snum = to_string(num);
        int res = 0, i = 0, n = snum.size();
        bool oneFound = false;
        while(i < n){
            int d = snum[i] - '0';
            if(d == 1 or d == 0){
                oneFound = true;
                res = res*10 + d;
                i++;
            }
            else{
                break;
            }
        }
        if(i == n)
            return res;
        int x = snum[i] - '0';
        while(i < n){
            int d = snum[i] - '0';
            if(d == x){
                res = res*10 + !oneFound;
            }
            else{
                res = res*10 + d;
            }
            i++;
        }
        return res;
    }
    int maxDiff(int num) {
        return findMax(num) - findMin(num);
    }
};