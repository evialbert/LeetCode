class Solution {
public int eliminateMaximum(int[] dist, int[] speed) {
    double[] arrtime=new double[speed.length];
    for(int i=0;i<dist.length;i++){
        arrtime[i]=((double)dist[i]/(double)speed[i]);
    }
    Arrays.sort(arrtime);
    int count=1;
    int i=1;
    while(i<arrtime.length){
        if(arrtime[i]>i)
            count++;
        else 
            break;
        i++;
    }
    return count;
}
}
