class Solution {   
public String dayOfTheWeek(int day, int month, int year) {
        String[] week = { "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday" };
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 1; i <= 12; i++) {
            if (i == 2)
                map.put(i, 28);
            else if (i == 4 || i == 6 || i == 9 || i == 11)
                map.put(i, 30);
            else
                map.put(i, 31);
        }

        int count = 0;
        for (int i = 1971; i < year; i++) {
            if (i % 4 == 0 && ((i % 100 != 0) || (i % 400 == 0)))
                count += 366;
            else
                count += 365;
        }

        if (year % 4 == 0 && ((year % 100 != 0) || (year % 400 == 0)))
            map.put(2, 29);

        int total = 0;
        for (int i = 1; i < month; i++)
            total += map.get(i);

        int totalTillTheDate = count + total + day;

        int rem = (totalTillTheDate) % 7;

        return week[rem];
    }
}