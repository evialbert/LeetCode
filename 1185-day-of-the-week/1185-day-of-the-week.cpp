class Solution {
public:
    const string answers[7]{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    const int days[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    string dayOfTheWeek(int day, int month, int year) {
        long long d = day; 
        for (int i = 1968; i < year; i++) // 168.01.01 - monday
            d += (abs(i - 2000) % 4 == 0) ? 366 : 365;
        d += (abs(year - 2000) % 4 == 0 and year != 2100 and month > 2); // 2000 - leap, 2100 - not
        d += accumulate(begin(days), begin(days) + month - 1, 0);
        return answers[d % 7];
    }
};