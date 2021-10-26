class Solution {
    public int maxLength(List<String> arr) {
//      List to store all the unique strigs   
        ArrayList<String> res = new ArrayList<>();
//         add empty string so that we can get started with concatination
        res.add("");
        for(String s : arr){
//            if the string in the array is itself having repeating characters donot consider it 
            if(isUnique(s)){
                ArrayList<String> currList = new ArrayList<>();
//                 concatinate the present string under consideration with each string in res array
                for(String str : res){
                    String newString = str+s;
//                     add only unique concationation to currList
                    if(isUnique(newString)){
                        currList.add(newString);
                    }
                }
//                 add all of the currList to res
                res.addAll(currList);
            }
        }
//         find the largest length of the strings in the res
        int maxLen = 0;
        for(String ele : res){
            maxLen = Math.max(maxLen, ele.length());
        }
//         return that length
        return maxLen;
    }
    public boolean isUnique(String s){
	//if len is greater than 26 then there must be repetitions
        if(s.length() > 26) return false;
		// frequency array
        int chars[] = new int[26];
        for(char c : s.toCharArray()){
            chars[c - 'a']++;
			//if frequency of any character is greater than 1, return false
            if(chars[c-'a'] > 1) return false;
        }
        return true;
    }
}