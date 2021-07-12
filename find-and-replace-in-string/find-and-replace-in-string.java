class Solution {
    public String findReplaceString(String s, int[] indices, String[] sources, String[] targets) {
        HashMap<Integer, String> sourceIndex = new HashMap<>();
        HashMap<Integer, String> targetIndex = new HashMap<>();
        for(int i=0; i<indices.length; i++){
            sourceIndex.put(indices[i], sources[i]);
            targetIndex.put(indices[i], targets[i]);
        }
        Arrays.sort(indices);
        StringBuilder str = new StringBuilder(s);
        for(int i=indices.length-1; i>=0; i--){
            int index = indices[i];
            String source = sourceIndex.get(index);
            StringBuilder target = new StringBuilder(targetIndex.get(index));
            if(str.substring(index, index+source.length()).toString().equals(source)){
                str = new StringBuilder(str.substring(0, index)).append(target).append(new StringBuilder(str.substring(index+source.length())));
            }
        }
        return str.toString();
    }
}