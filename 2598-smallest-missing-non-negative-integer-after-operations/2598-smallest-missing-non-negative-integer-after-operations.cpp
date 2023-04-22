class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> v(value,0);
        // cout<<"#";
        int aaa = value;
        for(int i = 0; i <aaa; i++){};
        for(auto &i: nums){
            // cout<<(i%value);
            v[((i%value)+value)%value]++;
        }
        // cout<<"#";
        int x = 0;
        int mx = INT_MAX;
        for(auto &i: v){
            if(i<mx){
                x = 0;
                mx = i;
            }
            if(mx==i){
                x++;
            }
        }
        // cout<<"#";
        if(x==value){
            return x*mx;
        }
        for(int i = 0; i < value; i++){
            if(v[i]==mx){
                return mx*value+i;
            }
        }
        // cout<<"#";
        return value;
    }
};