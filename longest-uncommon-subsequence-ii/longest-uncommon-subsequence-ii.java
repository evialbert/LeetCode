class Solution {
    public int findLUSlength(String[] strs) {
        int result = -1;
        for(int i = 0; i < strs.length; i++){
            boolean issubsequence = false;
            for(int j = 0; j < strs.length; j++){
                if(i != j){
                    if(helper(strs[i], strs[j])){
                        issubsequence = true;
                        break;
                    }
                }
            }
            if(!issubsequence){
                    result = Math.max(result, strs[i].length());
                }
        }
        return result;
    }
    
    private boolean helper(String a, String b){
        if(a.length() > b.length()){
            return false;
        }
        char[] arr1 = a.toCharArray();
        char[] arr2 = b.toCharArray();
        int i = 0;
        int j = 0;
        while(j < arr2.length){
            if(i < arr1.length && arr2[j] == arr1[i]){
                i++;
            }
            
            j++;
        }
        if(i == arr1.length){
            return true;
        }else{
            return false;
        }
    }
}