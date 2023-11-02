class Solution {

    public static int histogram(int[] heights){
         int n = heights.length;

        ArrayDeque<Integer> st1 = new ArrayDeque<>();
        ArrayDeque<Integer> st2 = new ArrayDeque<>();

        int left[] = new int[n];
        int right[] = new int[n];

        //previous smaller element
        for(int i = 0; i < n; i++){

            int num = heights[i] ;

            while(!st1.isEmpty() && heights[st1.peek()] > num)
                st1.pop();

            if(st1.isEmpty())
                left[i] = -1;
            else 
                left[i] = st1.peek();

            st1.push(i);            

        }
    

        //next greater element
        for(int i = n-1; i >= 0; i--){

            int num = heights[i];

            while(!st2.isEmpty() && heights[st2.peek()] >= num)
                st2.pop();

            if(st2.isEmpty())
                right[i] = n;
            else 
                right[i] = st2.peek();

            st2.push(i);            

        }

        int max = Integer.MIN_VALUE;
        for(int i = 0; i < n; i++){

            int sum = (right[i] - left[i] - 1) * (heights[i]);
            max = Math.max(max, sum); 

        }

        System.out.println("Max"+ max);
        return max;
    }

    public int maximalRectangle(char[][] matrix) {
        
        int n = matrix.length;
        int m = matrix[0].length;
        int[] currRow = new int[matrix[0].length];
        int max = 0;

        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                if(matrix[i][j] == '1')
                    currRow[j]++;
                else 
                    currRow[j] = 0;    
            }

            int currMax = histogram(currRow);
            max = Math.max(max, currMax);

        }

        return max;
        
    }
}