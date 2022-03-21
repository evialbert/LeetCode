class Solution {
    public double trimMean(int[] arr) {
        int amount = arr.length*5/100;
        Arrays.sort(arr);
        double sum=0; double count=0;
        for(int i = amount; i < arr.length-amount; i++){
            sum+=arr[i];
            count+=1;
        }
        return sum/count;
    }
}