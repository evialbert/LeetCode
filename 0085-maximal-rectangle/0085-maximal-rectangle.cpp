class Solution {
public:
    
    int maxAreaHistogram(vector<int>& matrix)
    {
        stack<int>myStack;
        int ptr,width,tmpArea=0,maxArea=0,sz = matrix.size();
        
        for( int i = 0; i < sz; i++ )
        {
            if( myStack.size() == 0 || matrix[myStack.top()] <= matrix[i] )
            {
                myStack.push(i);
            }
            else
            {
                while( myStack.size() != 0 && matrix[myStack.top()] > matrix[i] )
                {
                    ptr = myStack.top();
                    myStack.pop();
                    
                    width = ( myStack.size() == 0 ? i : i-myStack.top()-1 );
                    tmpArea = matrix[ptr]*width;
                    
                    maxArea = max(tmpArea,maxArea);
                }
                myStack.push(i);
            }
        }
        
        if( myStack.size() == 0 ) return maxArea;
        
        int last = myStack.top()+1;
        
        while( myStack.size() != 0 )
        {
            ptr = myStack.top();
            myStack.pop();
                    
            width = ( myStack.size() == 0 ? last : last-myStack.top()-1 );
            tmpArea = matrix[ptr]*width;
                    
            maxArea = max(tmpArea,maxArea);
        }
        
        return maxArea;
      
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if( matrix.empty() ) return 0;
        
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        int maxArea = 0;
        
        vector<vector<int>>grid(rowSize,vector<int>(colSize,0));
        
        for( int i = 0; i < rowSize; i++ )
        {
            for( int j = 0; j < colSize; j++ )
            {
                grid[i][j] = ( matrix[i][j] == '1' ? 1 : 0 );
                if( i != 0 && grid[i][j] == 1 ) grid[i][j] += grid[i-1][j];
            }
            
            int tmpAns = maxAreaHistogram(grid[i]);
            maxArea = max(maxArea,tmpAns);
        }

        return maxArea;
        
    }
};