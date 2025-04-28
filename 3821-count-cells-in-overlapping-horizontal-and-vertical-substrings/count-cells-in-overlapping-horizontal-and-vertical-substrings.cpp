class Solution{
public:
    // Z-Algorithm
    vector<int> getIndices(string S , string P){
		string ZS = P + "#" + S;
		int N = ZS.size();

        vector<int> Z(N , 0);
	    for(int i = 1 , L = 0 , R = 0 ; i < N ; i++){
	        if(i < R) Z[i] = min(R - i , Z[i - L]);
	        while(i + Z[i] < N && ZS[Z[i]] == ZS[i + Z[i]]) Z[i]++;
	        if(i + Z[i] > R) R = i + Z[L = i];
	    }

        vector<int> indices;
		for(int i = 0 ; i < Z.size() ; i++){
			if(Z[i] == P.size()){
				indices.push_back(i - P.size() - 1);
			}
		}

 		return indices;
    }

    int countCells(vector<vector<char>> &A , string P){
        int N = A.size() , M = A[0].size();
        
        // flatten horizontally and vertically by wrapping
        string H , V;
        for(int i = 0 ; i < N ; i++) for(int j = 0 ; j < M ; j++) H.push_back(A[i][j]);
        for(int j = 0 ; j < M ; j++) for(int i = 0 ; i < N ; i++) V.push_back(A[i][j]);

        // get Indices where the pattern matches;
        vector<int> H_indices = getIndices(H , P);
        vector<int> V_indices = getIndices(V , P);

        // use difference arrays to mark the cells optimally
        vector<int> H_mark(N * M + 2 , 0);
        vector<int> V_mark(N * M + 2 , 0);

        // marking horizontal ranges
        for(int index : H_indices){
            H_mark[index] += 1;
            H_mark[index + P.size()] -= 1;
        }
        
        // marking vertical ranges
        for(int index : V_indices){
            V_mark[index] += 1;
            V_mark[index + P.size()] -= 1;
        }

        // marking all the cells in horizontal and vertical ranges
        for(int i = 1 ; i < N * M ; i++){
            H_mark[i] += H_mark[i - 1];
            V_mark[i] += V_mark[i - 1];
        }
        
        int goodCells = 0;

        // count cells covered by both
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                int Count_H_mark = H_mark[i * M + j];
                int Count_V_mark = V_mark[j * N + i];
                if(Count_H_mark > 0 && Count_V_mark > 0){
                    goodCells++;
                }
            }
        }
        
        return goodCells;

    }
};