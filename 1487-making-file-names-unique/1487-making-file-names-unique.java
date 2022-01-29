class Solution {
    public String[] getFolderNames(String[] names) {
        String []ans= new String[names.length];
        Map<String,Integer>mp= new HashMap<>();
		
        for(int i=0;i<names.length;i++) {
		
            if(mp.containsKey(names[i])){
                Integer idx = mp.get(names[i]);
                StringBuilder sb = new StringBuilder(names[i]);
                sb.append('('); sb.append(idx); sb.append(')');
				
                while(mp.containsKey(sb.toString())){
                    idx++;
                    sb = new StringBuilder(names[i]);
                    sb.append('('); sb.append(idx); sb.append(')');
                }
				
                ans[i]=sb.toString();
                mp.put(sb.toString(),1);
                mp.put(names[i],idx+1);
            }
			
            else{
                ans[i]=names[i];
                mp.put(names[i],1);
            }
        }
        return ans;
    }
}