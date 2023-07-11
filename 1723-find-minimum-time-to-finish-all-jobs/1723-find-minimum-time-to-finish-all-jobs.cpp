class Solution {
public:
    
    bool is_possible(vector<int>& arr, int i, int n, int mid, vector<int>& worker, int k)
    {
        // base case
        
        if(i == n)
            return true;
        
        // assign the curr_work to the workers which can do the curr_work
        
        for(int j = 0; j < k; j++)
        {
            if(worker[j] + arr[i] <= mid)
            {
                worker[j] += arr[i];
                
                if(is_possible(arr, i + 1, n, mid, worker, k))
                    return true;
                
                worker[j] -= arr[i];
            }
            
            // if any of the worker doesn't get any job then this combination will not produce optimal result
            
            if(worker[j] == 0)
                break;
        }
        
        return false;
    }
    
    int minimumTimeRequired(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        // sort the array in descending order
        
        sort(arr.begin(), arr.end(), greater<int> ());
        
        int mini = INT_MAX;
        
        // apply binary search on search space {low, high}
        
        int low = *max_element(arr.begin(), arr.end());
            
        int high = 0;
            
        for(int i = 0; i < n; i++)
        {
            high += arr[i];
        }
            
        int ans = -1;
        
        // for every mid, distribute the works into k worker then take min. of ans
            
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            
            vector<int> worker(k, 0);
                
            if(is_possible(arr, 0, n, mid, worker, k))
            {
                ans = mid;
                    
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
            
        mini = min(mini, ans); 
        
        return mini;
    }  
};