class Solution {
public:
class UF {
    public:
        vector<int> par;
        vector<int> rank;
        int seperate;//number of seperate component
        UF(int n) {
            for (int i = 0; i < n; i++) {
                par.push_back(i);
                rank.push_back(0);
            }
            seperate = n;
        }
        int findfather(int x) {
            while (x != par[x]) {
                par[x] = par[par[x]];
                x = par[x];
            }
            return x;
        }
        int unionnodes(int x1, int x2) {//return 0 if the two component is already connected, 1 otherwise (union success)
            int p1 = findfather(x1);
            int p2 = findfather(x2);
            if (p1 == p2) {
                return 0;
            }
            if (rank[p1] > rank[p2]) {
                rank[p1] += rank[p2];
                par[p2] = p1;
            }
            else {
                rank[p2] += rank[p1];
                par[p1] = p2;
            }
            seperate -= 1;
            return 1;
        }
        bool isConnected() {
            return seperate <= 1;
        }
    };
    bool canTraverseAllPairs(vector<int>& nums) {
        if (nums.size()==1) return true;
        UF* u = new UF(nums.size());
        //sqrt(100000) = 316
        vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313};
        unordered_map<int,int> num;
        for (int i=0; i< nums.size();i++){
            num[nums[i]]++;
        }
        if (num.size()==1 && nums[0] !=1) return true;
        unordered_map<int,vector<int>> mp;//key:value - prime factor: index
        for (int i=0; i< nums.size();i++){
            int n = nums[i];
            //find prime factors of n
            bool bigprime = true;
            for (int j=0; j< prime.size();j++){
                if (n< prime[j]) break;
                if (n % prime[j] ==0){
                    bigprime = false;
                    while (n % prime[j] ==0){
                        n /= prime[j];
                    }
                    mp[prime[j]].push_back(i);
                }
            }
            //add the remaining prime part of n to the hash map (big primes)
            if (n >316 && bigprime && mp.find(n) == mp.end()){
                int multiple = 1;
                bool returnfalse = true;
                while (multiple * n <=100000){
                    if (multiple * n != nums[i] && num.find(multiple * n) != num.end()  ){
                        returnfalse = false;
                        break;
                    }
                    multiple++;
                }
                if (returnfalse) return false;//single element with big prime factors
                prime.push_back(n);
                sort(prime.begin(),prime.end());
                mp[n].push_back(i);
            }

        }
        for (auto &e: mp){
            for (int i=1; i< e.second.size();i++){
                u-> unionnodes(e.second[i],e.second[i-1]);
                if (u ->isConnected()){
                    return true;
                }
            }
        }
        return false;
    }
};