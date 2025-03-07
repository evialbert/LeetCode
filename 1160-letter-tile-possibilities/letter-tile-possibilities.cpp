class Solution {
public:
    void count(vector<int> &arr, int n, int &ans){
        //checks if every place is filled.
        if(n <= 0) return; 
        //checking for letters which can be filled at nth index.
        for(int i = 0; i < 26; i++){
            if(arr[i] > 0){
                // Reducing its occurence.
                arr[i]--; 
                ans++;
                count(arr, n - 1, ans);
                //Restoring its occurence for furthur combination./Backtracking.
                arr[i]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        vector<int> arr(26, 0);
        //Occurence count array.
        for(int i = 0; i < tiles.size(); i++){
            arr[int(tiles[i]) - 65]++;
        }
        int ans = 0; 
        count(arr, tiles.size(), ans); 
        return ans; 
    }
};