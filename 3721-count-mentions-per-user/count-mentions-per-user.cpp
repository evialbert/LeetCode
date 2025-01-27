class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](auto const& e1, auto const& e2) {
            int t1 = stoi(e1[1]), t2 = stoi(e2[1]);
            if(t1 == t2)
                return e1[0][0] > e2[0][0];
            return t1 < t2;
            });
            
        vector<int> onlines(n, 0);
        auto offline = [&onlines] (int t, int id) {
            onlines[id] = t + 60;
        };
        vector<int> mentions(n,0);
        auto message = [&mentions, &onlines, n] (int t, string const& ids) {
            if(ids == "ALL") {
                for(auto & m : mentions) ++m;
            }
            else if(ids == "HERE") {
                for(int id = 0; id < n; ++id) {
                    if(t >= onlines[id])
                        mentions[id]++;
                }
            }
            else {
                for(int i = 2; i < ids.size(); ) {
                    auto j = ids.find(' ', i);
                    if(j == string::npos) j = ids.size();
                    int id = stoi( ids.substr(i, j - i) );
                    mentions[id]++;
                    i = j + 3;
                }
            }
        };
        for(auto const& e : events) {
            int t = stoi(e[1]);
            if(e[0][0] == 'M') {
                message(t, e[2]);
            }
            else
                offline(t, stoi(e[2]));
        }
        return mentions;
    }
};