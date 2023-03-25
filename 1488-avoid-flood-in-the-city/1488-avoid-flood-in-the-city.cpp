class Solution {
public:

    
    vector<int> avoidFlood(vector<int>& rains) {
        // used for storing last index of the element
        map<int, int> mp;
        // used to store the indices of zeros
        set<int> zeros;
        int n = rains.size(); 
        // used to store the answer vector
        vector<int> ans(n);
        
        for(int i=0; i < n; i++){
            int el = rains[i];
            // if the element is zero, just we need to record the zeros indices
            if(el == 0){
                zeros.insert(i);
            }
            
            else{
                // if it is not zero, then ans[i] = -1 by question
                ans[i] = -1;
                //occuring for the first time
                if(mp.find(el) == mp.end()){
                    mp[el] = i;
                }
                else{
                    //already occured
                    int last_index = mp[el];
                    auto it = zeros.upper_bound(last_index);
                    //check if zero exists after it
                    if(it == zeros.end()){
                        //this means no zero found after it
                        return {};
                    }
                    
                    else{
                        //zeros occur after it
                        int zero_index_after_last_occur = *it;
                        // remove element from set as zero is used now
                        zeros.erase(it);
                        // change the last index of el to current index as it has again occured
                        mp[el] = i;
                        // update the answer to the el that is dried
                        ans[zero_index_after_last_occur] = el;
                    }
                }
                
            }
            
        }
        
        for(auto it: zeros){
            ans[it] = 1;
        }
        return ans;
    }
};