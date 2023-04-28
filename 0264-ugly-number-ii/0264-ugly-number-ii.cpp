
class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> set;
        long nthNumber = 1;
        set.insert(nthNumber);
        for(int i=0; i<n; i++){
            nthNumber = *set.begin();
            set.erase(nthNumber);
            set.insert(nthNumber*2);
            set.insert(nthNumber*3);
            set.insert(nthNumber*5);
        }
        return nthNumber;
    }
};