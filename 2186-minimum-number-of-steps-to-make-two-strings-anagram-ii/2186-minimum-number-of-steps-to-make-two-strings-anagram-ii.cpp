class Solution {
public:
    int minSteps(string s, string t) {
        
        int count=0;
        //take an array of 26 size to store frequency of alphabets
        vector<int> arr(26,0);
        
        
        //increment the frequency of character by 1 in the array
        for(auto i:s)
            arr[i-'a']++;
        
        //decrement the frequency of character by 1 in the array
        for(auto i:t)
            arr[i-'a']--;
        
        // Now the array will only store the frequency of characters that are different
        for(auto i:arr)
            count+=abs(i);
        
        return count;
        
        
        
    }
};