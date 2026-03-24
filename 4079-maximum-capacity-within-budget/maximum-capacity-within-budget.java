class Solution {
    public int maxCapacity(int[] costs, int[] capacity, int budget) {
        //choose at most 2 distinct machines such that 
        //total cost< budget
        //return maximum available capacity
        //lets make the array by cost 

        int n = costs.length;
        int[][] m = new int[n][2];
        for (int i = 0; i < n; i++) {
            m[i][0] = costs[i];
            m[i][1] = capacity[i];
        }

        Arrays.sort(m, (a, b) -> Integer.compare(a[0], b[0]));
        //now finding the prefix maximum capacities  till that index because we are not returning costs

        int[] pm = new int[n];
        pm[0] = m[0][1];
        for (int i = 1; i < n; i++) {
            pm[i] = Math.max(pm[i-1], m[i][1]);
        }

        //now we are finding the capacity to be returned 
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int c1 = m[i][0];
            int cap1 = m[i][1];
            //for only 1 machine 
            if (c1 < budget) {
                ans = Math.max(ans, cap1);
            } else {
                break;
            }
            //for 2 machines 
            //for reducing the time complexity we are using binary search

            int remaining_budget = budget - 1 - c1;

            if (remaining_budget < 0) {
                continue;
            }
            int left= 0, right = n - 1, idx = -1;

            while (left <= right) {
                int mid=(left+right)/2;
                if(m[mid][0]<=remaining_budget)
                {
                    idx=mid;
                    left=mid+1;
                }
                else
                {
                    right=mid-1;
                }
            }
            if(idx==-1)
            {
                continue;
            }
            int add_cap=pm[idx];

            if(idx>=i&& m[i][1]==add_cap)
            {
                if(i>0)
                {
                    add_cap=pm[i-1];
                }
                else
                {
                    continue;
                }
            }
            ans=Math.max(ans,cap1+add_cap);
        }
        return ans;
    }
}