class Solution {
    public int numRescueBoats(int[] people, int limit) {
         Arrays.sort(people);
         
        int i = 0;
        int j = people.length - 1;
        int boatCount = 0;
      
        while(i <= j){
          if(people[i] + people[j] <= limit){
            //place both ith & jth people on your boat
            boatCount++;
            i++;
            j--;
          }
          else{
            //greedily place your heaviest person on your boat 
             boatCount++;
             j--;
          }
        }
      return boatCount;
    }
}