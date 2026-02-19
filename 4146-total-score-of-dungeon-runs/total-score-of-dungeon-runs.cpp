class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int N = damage.size();
        long long res=0;
        for(int i=1; i<N; i++) damage[i]+=damage[i-1];
        for(int i=0; i<N; i++){
            int target = hp-requirement[i];
            if(target >= damage[i]){
                res+=i+1;
                continue;
            }
            int left=0;
            int right=i;
            int mid=0;
            while(left<right){
                mid = (left+right)/2;
                int currDamage = damage[i]-damage[mid];
                if(target > currDamage) right=mid;
                else if(target < currDamage) left=mid+1;
                else break;
            }
            mid = (target >= damage[i]-damage[mid])?mid:mid+1;
            res+=max(i-mid,0);
        }
        return res;
    }
};