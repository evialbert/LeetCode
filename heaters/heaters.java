class Solution {
    public int findRadius(int[] houses, int[] heaters) {
		Arrays.sort(houses);
		Arrays.sort(heaters);
		
		int minRadius = 0;
        int j=0;
		for(int i=0;i<houses.length;i++){
            int house=houses[i];
            while(j<heaters.length&&house>heaters[j])
                j++;
            j=Math.min(j,heaters.length-1);
			if(j==0) {
				minRadius=Math.max(minRadius,Math.abs(heaters[j]-house));
			} else if(j== heaters.length-1&&house>=heaters[j]) {
				minRadius=Math.max(minRadius,houses[houses.length-1]-heaters[j]);
                break;
			} else {
				minRadius=Math.max(minRadius,Math.min(house-heaters[j-1],heaters[j]-house));
			}
		}
		return minRadius;
    }
}