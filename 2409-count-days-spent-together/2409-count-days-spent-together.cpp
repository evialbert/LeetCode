class Solution {
public:
    unordered_map<int, int> map;
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        map[1] = 31;
        map[2] = 28;
        map[3] = 31;
        map[4] = 30;
        map[5] = 31;
        map[6] = 30;
        map[7] = 31;
        map[8] = 31;
        map[9] = 30;
        map[10] = 31;
        map[11] = 30;
        map[12] = 31;

        int start1 = transfer(arriveAlice);
        int end1 = transfer(leaveAlice);

        int start2 = transfer(arriveBob);
        int end2 = transfer(leaveBob);


        if(start1 > end2 || start2 > end1) {
            return 0;
        }

        return abs(end1-start1) + abs(end2 - start2) - abs(max(end1, end2)-min(start1, start2)) + 1;
    }

    int transfer(string& time) {
        int month = stoi(time.substr(0,2));
        int days = stoi(time.substr(3,2));
        int res = 0;
        for(int i=1;i<month;i++) {
            res += map[i];
        }

        res += days;
        return res;
    }
};