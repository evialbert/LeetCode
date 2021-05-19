class Solution {
    
    public int desiredPerson(int n){
        if(n%2 == 0){
            return n+1;
        }
        return n-1;
    }

    public int minSwapsCouples(int[] row) {
        int[] indexMap = new int[row.length];
        for(int i = 0; i < row.length; i++){
            // map of where this person is sitting
            indexMap[row[i]] = i;
        }
        
        int numSwaps = 0;
        for(int i = 0; i < row.length-1; i = i+2){
            // who person[i] wants to sit with
            int wanted = desiredPerson(row[i]);
            // not sitting with who they want to
            if(row[i+1] != wanted){
                // where the partner is currently sitting
                int wantedIndex = indexMap[wanted];
                // person that person[i] currently sitting with
                int current  = row[i+1];
                // swap my current partner with the wanted one
                row[i+1] = row[wantedIndex];
                row[wantedIndex] = current;
                // update seat map
                indexMap[current] = wantedIndex;
                indexMap[wanted] = i+1;
                numSwaps++;
            }
        }
        return numSwaps;
    }
}