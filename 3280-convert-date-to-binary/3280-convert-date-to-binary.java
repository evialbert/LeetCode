public class Solution {  // Change the class name to 'Solution'
    public String convertDateToBinary(String date) {
        // Split the date into year, month, and day
        String[] parts = date.split("-");
        int year = Integer.parseInt(parts[0]);
        int month = Integer.parseInt(parts[1]);
        int day = Integer.parseInt(parts[2]);

        // Convert each part to binary
        String yearBinary = Integer.toBinaryString(year);
        String monthBinary = Integer.toBinaryString(month);
        String dayBinary = Integer.toBinaryString(day);

        // Combine the binary representations in year-month-day format
        return yearBinary + "-" + monthBinary + "-" + dayBinary;
    }
    
    public static void main(String[] args) {
        // Test case
        String param_1 = "2080-02-29";
        String result = new Solution().convertDateToBinary(param_1);  // Updated class name here too
        System.out.println(result);  // Output: "100000100000-10-11101"
    }
}