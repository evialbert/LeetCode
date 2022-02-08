class Solution {
    public String reformatDate(String date) {
        Map<String,String> months = new HashMap<>();
        
        //maintain month string to month number in a hashmap
        months.put("Jan","01");
        months.put("Feb","02");
        months.put("Mar","03");
        months.put("Apr","04");
        months.put("May","05");
        months.put("Jun","06");
        months.put("Jul","07");
        months.put("Aug","08");
        months.put("Sep","09");
        months.put("Oct","10");
        months.put("Nov","11");
        months.put("Dec","12");
        
        //split the string date based on space so that we can get three separate strings of day, month and year
        String[] dates = date.split(" ");
        
        //take StringBuilder as String is immutable in Java
        StringBuilder formatedDate = new StringBuilder();
        
        //append year as it is
        formatedDate.append(dates[2]+"-");
        
        //append month using map
        formatedDate.append(months.get(dates[1])+"-");
        
        //fetch day by removing last 2 characters
        String day = dates[0].substring(0,dates[0].length()-2);
        
        // if day is a single digit, then need to append 0 first then the day else append day as it is
        if(day.length() == 1)
            formatedDate.append("0"+day);
        else formatedDate.append(day);
                            
        return formatedDate.toString();       
        
    }
}