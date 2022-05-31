class Solution {
    public int maximumScore(int a, int b, int c) {
        PriorityQueue<Integer> q = new PriorityQueue<>(Collections.reverseOrder()); // create your priority queue(max heap) in reverse order
        int score =0;
        //add a,b,c to heap only when their values are greater than 0 
        if(a>0) q.add(a);
        if(b>0) q.add(b);
        if(c>0) q.add(c);
        // finally the size of the heap should be more than or equal to  2 for getting a point 
       
        
        if(q.size() >=2){
            /* below while loop does the following 
                example if q =>(6,4,2)
                so, pass 1 : remove()=> val1,val2 = 6,4
                                        score++=1,val1--,val2--=5,3
                                        val1>0 add(val1),val2>0 add(val2) => q=>(5,3,2)
                    pass 2 : remove()=> val1,val2 = 5,3
                                        score++ = 2, val1--,val2-- = 4,2
                                        val1>0 add(val1),val2>0 add(val2) => q=>(4,2,2)
                    pass 3 : remove()=> val1,val2 = 4,2
                                        score++ = 3, val1--,val2-- = 3,1
                                        val1>0 add(val1),val2>0 add(val2) => q=>(3,2,1)
                    pass 4 : remove()=> val1,val2 = 3,2
                                        score++ = 4, val1--,val2-- = 2,1
                                        val1>0 add(val1),val2>0 add(val2) => q=>(2,2,1)
                    pass 5 : remove()=> val1,val2 = 2,2
                                        score++ = 5, val1--,val2-- = 1,1
                                        val1>0 add(val1),val2>1 add(val2) => q=>(1,1,1)     
                    pass 6 : remove()=> val1,val2 = 1,1
                                        score++ = 6, val1--,val2-- = 0,0
                                        val1>0 false,val2>0 false => q=>(1)=> as q.size() < 2=> exit     
					return score = 6;
                */
            while(q.size()>=2){
                int val1 = q.remove();
                int val2 = q.remove();
                score++;
                val1--;
                val2--;
                if(val1>0) q.add(val1);
                if(val2>0) q.add(val2);
            }
        }
        return score;
    }
}