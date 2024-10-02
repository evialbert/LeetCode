class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int>s;
        for(int &num:arr){
            s.insert(num);
        }
        int rank=1;
        unordered_map<int,int>mpp;
        for(auto it=s.begin();it!=s.end();++it){
            mpp[*it]=rank;
            ++rank;
        }
        const int m=arr.size();
        for(int i=0;i<m;++i){
            arr[i]=mpp[arr[i]];
        }
        return arr;
    }
};