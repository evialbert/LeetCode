class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        // populate map[factor] = free_copies.

        // compute frequency of factors in "d[factor]=freq"
        unordered_map<int,int> d{};
        int n = items.size();
        double lowest_cost = 3000.0;
        for(int i = 0 ; i < n ; ++i){
            double cost = (double) items[i][1];
            lowest_cost = min(lowest_cost, cost);
            d[items[i][0]]++;
        }
        int lowest_costi = (int) lowest_cost;
        // how many free copies for a given factor
        //  free_copies[factor] = free copies
        unordered_map<int,int> free_copies{};
        for(auto &[k,v]: d){
            int factor = k;
            int free_copy_count = v;
            int times = 1;
            int t = factor * times;
            while (t <= 1500){
                ++times;
                t = factor * times;
                if(d.contains(t) > 0){
                    free_copy_count += d[t];
                }
            }
            free_copies[factor] = free_copy_count;
        }

        // arange them in a sorted list freebies<cost_per_unit, cost>
        vector<pair<double, double>> freebies{};
        freebies.reserve(n);
        for(int i = 0 ; i < n ; ++i){
            double cost = items[i][1];            
            double free_copy_count = free_copies[items[i][0]];
            if(free_copy_count == 0) continue; // no benefit
            double cost_per_unit = cost / (free_copy_count);             
            if(cost_per_unit > lowest_cost) continue; // no better than just buy the lowest_cost unit
            freebies.push_back({cost_per_unit, cost});
        }
        
        // have one table:
        //     freebies<pair<double,double>> 1st index is the cost/free_copies (cost per unit), 2nd index is the cost. We can get free_copies by 2nd_index/1st_index.
        // And we have lowest cost of a single item . Already freebies are only containing table with values lower than min_cost per unit.
        //     min_cost, has the lowest cost of item.

        // we apply knapsack DP solution to freebies for budget 
        // unit inside is the unit_count.
        // dp[w] = max(dp[w], dp[w-cost[i]])
        vector<int> dp (budget+1,0);
        int best = 0;
        for(int i = 0 ; i < freebies.size(); ++i){
            double best_cost_per_unit = freebies[i].first;
            double cost = freebies[i].second;
            int costi = static_cast<int>(cost);
            double units = cost / best_cost_per_unit;
            int units_i = static_cast<int>(round(units));
            for(int w = budget ; w >= costi ; --w){
                int curr = dp[w];
                int proposed = dp[w-costi]+units_i;
                if(proposed > curr){
                    dp[w] = proposed;
                    if(best < dp[w] + ((budget-w)/lowest_costi)){
                        best = dp[w] + ((budget-w)/lowest_costi);
                    }
                }                   
            }
        }
        return best;
    }
};