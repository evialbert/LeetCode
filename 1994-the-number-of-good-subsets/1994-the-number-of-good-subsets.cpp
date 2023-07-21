class Solution {
public:
    long modulo = 1e9 + 7, result = 0;
    int primes[10] = {2,3,5,7,11,13,17,19,23,29};
    int nonprimes[8] = {6,10,14,15,21,22,26,30};
    int count[31];
    vector<int> bit_rep;
    long powerOfTwo(int x) {
        long result = 1;
        while(x--)result = (result * 2) % modulo;
        return result;
    }
    void dfs(int index, int cur_set_bits, long countSoFar,long debug){
        if(index == 8) {
            for(int prime : primes) {
                if((cur_set_bits & bit_rep[prime]) == 0) {
                    countSoFar = (countSoFar * (1 + count[prime])) % modulo;
                }
            }
            result = (result + countSoFar) % modulo;
            return ;
        }
        dfs(index+1,cur_set_bits, countSoFar, debug);
        if((cur_set_bits & bit_rep[nonprimes[index]]) == 0 && count[nonprimes[index]]!=0) {
            countSoFar = (countSoFar * count[nonprimes[index]]) % modulo;
            dfs(index+1, cur_set_bits|bit_rep[nonprimes[index]], countSoFar, debug * nonprimes[index]);
        }
    }
    int numberOfGoodSubsets(vector<int>& nums) {
        bit_rep.clear(); bit_rep.resize(31, 0);
        for(int i : nums) count[i]++;
        for(int i : primes)bit_rep[i] = 1<<i;
        for(int i : nonprimes){
            for(int prime:primes)if(i % prime == 0)bit_rep[i] |= (1<<prime);
        }
        dfs(0,0,1,1);
        result = (result + modulo - 1) % modulo;
        result = (result * powerOfTwo(count[1])) %  modulo;
        return result;
    }
};