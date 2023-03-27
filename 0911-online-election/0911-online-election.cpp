class TopVotedCandidate {
public:
    vector<pair<int,int>> v;
    unordered_map<int,int> M;
    vector<int> times;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int one = 0;
        int zero = 0;
        int Max = 0;
        int person = 0;
        for(int i = 0 ; i < times.size() ; i++){
            M[persons[i]]++;
            if(M[persons[i]] >= Max){
                v.push_back(make_pair(times[i],persons[i]));
                Max = M[persons[i]];
                person = persons[i];
            } else v.push_back(make_pair(times[i],person));
        }
        this->times = times;
    }
    
    int q(int t) {
        auto s = lower_bound(times.begin(),times.end(),t + 1);
        
        return v[s - times.begin() - 1].second;
    }
};
/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */