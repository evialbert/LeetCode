class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        //same room can be chosen as many time as you want

        sort(rooms.begin(), rooms.end(), [&](auto& a, auto&b){
            return a[1] > b[1];
        });
        map<pair<int, int>, vector<int>> q_i;
        for (int i = 0; i < queries.size(); i++){
            q_i[pair<int, int>(queries[i][1], queries[i][0])].push_back(i);
        }

        int r_i = 0;
        set<int>ids;
        vector<int> ans(queries.size(), -1);
        for(auto curr = q_i.rbegin(); curr != q_i.rend(); curr++){
            int minSize = curr->first.first; int preferredId = curr->first.second;

            while (r_i < rooms.size() && rooms[r_i][1] >= minSize){
                ids.insert(rooms[r_i][0]);
                r_i++;
            }

            if(ids.size() == 0) continue;
            
            auto closest_id = ids.lower_bound(preferredId);//finds the first id not smaller than preferredId
            int c_ans = 100000000;
            if (closest_id != ids.end()){
                c_ans = *closest_id;
            }
            if (closest_id!=ids.begin()) closest_id--;
            if (preferredId - *closest_id <= c_ans - preferredId){
                c_ans = *closest_id;
            }

            for (int q_index: curr->second){
                ans[q_index] = c_ans;
            }

        }

        return ans;
    }
};