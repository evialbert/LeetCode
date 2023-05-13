class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> arr(n, 0), ans;
        int cnt = 0;
        for(auto it : queries)  {
            int ind = it[0], color = it[1];
            if(ind - 1 >= 0 && arr[ind - 1] == arr[ind] && arr[ind] != 0)    cnt--;
            if(ind+1<n && arr[ind+1] == arr[ind] && arr[ind] != 0)  cnt--;
            if(ind - 1 >= 0 && arr[ind - 1] == color)    cnt++;
            if(ind+1<n && arr[ind+1] == color)  cnt++;
            arr[ind] = color;
            ans.push_back(cnt);
        }
        
        return ans;
    }
};