class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        for(int i = 0;i<arr.size();i++){
            if(i > 0 &&  arr[i] == arr[i-1]) continue;
            int l = i+1, r = arr.size()-1;
            vector<int> temp;
            while(l < r){
                if(arr[i] + arr[l] + arr[r] == 0){
                    temp.emplace_back(arr[i]);
                    temp.emplace_back(arr[l]);
                    temp.emplace_back(arr[r]);
                    ans.emplace_back(temp);
                    while(l < arr.size()-1 && arr[l] == arr[l+1]){
                        l++;
                    }
                    while(r > 1 && arr[r-1] == arr[r]){
                        r--;
                    }
                    r--;l++;
                }
                else if(arr[i] + arr[l] + arr[r] > 0) r--;
                else l++;
                temp.clear();
                
            }
        }
        return ans;
    }
};