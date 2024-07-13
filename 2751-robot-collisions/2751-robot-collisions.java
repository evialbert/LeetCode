class Robo{
    int pos, health, dir;
    Robo(int pos, int health, char dir){
        this.pos = pos;
        this.health = health;
        this.dir = dir == 'R' ? 1 : -1;
    }
}
class Solution {
    public List<Integer> survivedRobotsHealths(int[] positions, int[] healths, String directions) {
        int n = positions.length;
        Robo robos[] = new Robo[n];   //for each robot store its positions, health, direction in one object
        for(int i = 0; i < n; i++)    robos[i] = new Robo(positions[i], healths[i], directions.charAt(i));
        Arrays.sort(robos, (r1, r2)->r1.pos - r2.pos); //sort the robots based on their positions
        Stack<Integer> st = new Stack<>();             //stores the index of surviving robot
        for(int i = 0; i < n; i++){
            boolean addCurrent = true;
            Robo currRobo =  robos[i];
            while(!st.isEmpty() && addCurrent){
                Robo prevRobo = robos[st.peek()];
                if(prevRobo.dir != currRobo.dir && prevRobo.dir == 1){ //collision
                    if(prevRobo.health > currRobo.health){ //previous robot survies
                        prevRobo.health--;                 //previous robot health decreased 
                        addCurrent = false;                //don't add current robot since it didn't survive
                    }
                    else{
                        st.pop();                          //previous robot didn't survive
                        if(prevRobo.health == currRobo.health)  addCurrent = false;  //if same health current robot also didn't survive
                        else    currRobo.health--;                                   //current robot survived but health decreased 
                    }
                }
                else    break; // no collision
            }
            if(addCurrent)  st.push(i);            //current robot survived
        }
        Map<Integer, Integer> posToHealth = new HashMap<>();  //mapping of position to health of surviving robots
        while(!st.isEmpty()){
            Robo r = robos[st.pop()];
            posToHealth.put(r.pos, r.health);
        }
        List<Integer> res = new ArrayList<>();
        //create the result order as per positions giving in input
        for(int i = 0; i < n; i++)  if(posToHealth.containsKey(positions[i])) res.add(posToHealth.get(positions[i]));
        return res;
    }
}