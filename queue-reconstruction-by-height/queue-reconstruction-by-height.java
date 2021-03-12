class Solution {
    public int[][] reconstructQueue(int[][] people) {
        if(people.length == 1) return people;

        Comparator<int[]> myComp = new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                if(a[1] > b[1]) return 1;
                else if(a[1] < b[1]) return -1;
                else{
                    if(a[0] > b[0]) return 1;
                    else return -1;
                }
            }
        };

        Arrays.sort(people, myComp);

        int len = people.length, total = 0;
        int[][] ans = new int[len][];

        for(int[] person : people){
            int count = 0;
            int i = 0;
            while(i < total){
                if(ans[i][0] >= person[0]) count++;
                if(count > person[1]) break;
                i++;
            }
            //i is the insert place, persons before i should move backward 1 step for the insert person
            for(int j = total - 1; j >= i; j--) ans[j + 1] = ans[j];
            ans[i] = person;
            total++;
        }

        return ans;
    }
}