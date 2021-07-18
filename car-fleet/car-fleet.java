class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        if (position.length == 0){
            return 0;
        }
        HashMap<Integer, Double> map = new HashMap();
        for (int i = 0; i < position.length; i++){
            map.put(position[i], (double)speed[i]);
        }
        
        Arrays.sort(position);
        int numFleet = 0;
        double[] etas = new double[position.length];
        for (int i = position.length - 1; i > 0; i--){
            int posFront = position[i];
            double etaFront = Math.max((target - posFront) / map.get(posFront), etas[i]);
            int posAft = position[i - 1];
            double etaAft = (target - posAft) / map.get(posAft);
            if (etaFront >= etaAft){
                etas[i - 1] = etaFront;
            }
            else if (etaFront < etaAft){
                numFleet++;
                etas[i - 1] = etaAft;
            }
        }
        numFleet++;
        return numFleet;
    }
}