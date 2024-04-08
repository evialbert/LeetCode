class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::queue q(std::deque<int>(students.begin(), students.end()));
        int index=0;
        int cnt= 0;
        while(!q.empty()){
            int curr= q.front();
            q.pop();
            if(curr != sandwiches[index]) cnt++,q.push(curr);
            else cnt= 0,index++;
            if(cnt== q.size()) break;
        }
        return q.size();
    }
};