class Solution {
    public int[] assignElements(int[] groups, int[] elements) {
        final int n = 100001;
        int helper[] = new int[n];

        for(int i = 0; i < n; i++){
            helper[i] = -1;
        }

        for(int i = 0 ; i < elements.length; i++){
            int el = elements[i];

            if(helper[el] != -1) {
                continue;
            }
            
            for(int index = el ;index < n; index += el){
                helper[index] = helper[index] == -1 ? i : helper[index];
            }
        }

        int[] assigned = new int[groups.length];

        for(int i = 0; i < assigned.length; i++) {
            assigned[i] = helper[groups[i]];
        }

        return assigned;
    }
}