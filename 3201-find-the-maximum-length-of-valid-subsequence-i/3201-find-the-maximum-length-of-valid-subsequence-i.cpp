class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int olen = 0;
        int elen = 0;
        int altlen1 = 0;
        int altlen2 = 0;
        bool a1 = true;
        bool a2 = false;
        for (auto x: nums){
            if (x%2 == 1){
                olen++;
                if (a1){
                    altlen1++;
                    a1 = !a1;
                }
                if (a2){
                    altlen2++;
                    a2 = !a2;
                }
            }
            else{
                elen++;
                if (!a1){
                    altlen1++;
                    a1 = !a1;
                }
                if (!a2){
                    altlen2++;
                    a2 = !a2;
                }
            }
        }
        return (max(max(olen,elen),max(altlen1,altlen2)));
    }
};